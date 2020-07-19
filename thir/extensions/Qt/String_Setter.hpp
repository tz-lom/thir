ValueSetter<Field, Next>
add(const ::QByteArray &str)
{
    char* const data = reinterpret_cast<char* const>(constructor->dynamicData(sizeof(char)*str.length(), fuse));
    ::std::copy(str.begin(), str.end(), data);
    return *static_cast<ValueSetter<Field, Next>*>(this);
}

ValueSetter<Field, Next>
add(const ::QString &str)
{
    return add(str.toUtf8());
}
