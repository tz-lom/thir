operator ::QString() const
{
    return ::QString::fromUtf8(dynamicData, dynamicSize);
}
