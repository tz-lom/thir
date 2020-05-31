operator ::QVector<type>() const
{
    ::QVector<type> result(size());
	const type* data = reinterpret_cast<const type*>(dynamicData);
	for(int i=result.size()-1; i>=0; --i)
	{
		result[i] = to_native(data[i]);
	}
	return result;
} 
