
#include "demofile.h"
#include "demotypes.h"
#include <cassert>

// DemoFileReader

DemoFileReader::DemoFileReader(FILE* fp):
    m_demoFp(fp)
{
}

int32_t DemoFileReader::ReadRawData(uint8_t* buffer, int32_t length)
{
    FILE* fp = m_demoFp;

    int32_t size;
    fread(&size, sizeof(int32_t), 1, fp);

    if (buffer && (length < size))
    {
        return -1;
    }

    if (buffer)
    {
        fread(buffer, 1, size, fp);
    }
    else
    {
        fseek(fp, size, SEEK_CUR);
    }
    return size;
}

void DemoFileReader::ReadSequenceInfo(int32_t& seqNum1, int32_t& seqNum2)
{
    FILE* fp = m_demoFp;
    fread(&seqNum1, sizeof(int32_t), 1, fp);
    fread(&seqNum2, sizeof(int32_t), 1, fp);
}

void DemoFileReader::ReadCmdInfo(democmdinfo_t& info)
{
    fread(&info, sizeof(democmdinfo_t), 1, m_demoFp);
}

void DemoFileReader::ReadCmdHeader(unsigned char& cmd, int32_t& tick)
{
    FILE* fp = m_demoFp;
    fread(&cmd, sizeof(unsigned char), 1, fp);
    fread(&tick, sizeof(int32_t), 1, fp);
    if (cmd >= 0)
    {
        assert(cmd <= dem_lastcmd);
    }
    else
    {
        cmd = dem_stop;
    }
}

int32_t DemoFileReader::ReadUserCmd(int32_t& sequenceNum, uint8_t* buffer, int32_t length)
{
    fread(&sequenceNum, sizeof(int32_t), 1, m_demoFp);
    return ReadRawData(buffer, length);
}

// DemoFileWriter

DemoFileWriter::DemoFileWriter(FILE* fp) :
    m_demoFp(fp)
{
}

void DemoFileWriter::WriteDemoHeader(const demoheader_t& header)
{
    fwrite(&header, sizeof(demoheader_t), 1, m_demoFp);
}

void DemoFileReader::ReadDemoHeader(demoheader_t& header)
{
    fread(&header, sizeof(demoheader_t), 1, m_demoFp);
}

void DemoFileWriter::WriteRawData(const uint8_t* buffer, int32_t length)
{
    FILE* fp = m_demoFp;
    fwrite(&length, sizeof(int32_t), 1, fp);
    fwrite(buffer, length, 1, fp);
}

void DemoFileWriter::WriteSequenceInfo(int32_t seqNum1, int32_t seqNum2)
{
    FILE* fp = m_demoFp;
    fwrite(&seqNum1, sizeof(int32_t), 1, fp);
    fwrite(&seqNum2, sizeof(int32_t), 1, fp);
}

void DemoFileWriter::WriteCmdInfo(const democmdinfo_t& info)
{
    fwrite(&info, sizeof(democmdinfo_t), 1, m_demoFp);
}

void DemoFileWriter::WriteCmdHeader(unsigned char cmd, int32_t tick)
{
    FILE* fp = m_demoFp;
    fwrite(&cmd, sizeof(unsigned char), 1, fp);
    fwrite(&tick, sizeof(int32_t), 1, fp);
}

void DemoFileWriter::WriteUserCmd(int32_t sequenceNum, const uint8_t* buffer, int32_t length)
{
    fwrite(&sequenceNum, sizeof(int32_t), 1, m_demoFp);
    WriteRawData(buffer, length);
}
