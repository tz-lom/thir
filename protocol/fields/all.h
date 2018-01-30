class FieldType
{
public:
    FieldType( const char* staticData, const char* dynamicData, SerializedData::hel dynamicSize):
        staticData(staticData),
        dynamicData(dynamicData),
        dynamicSize(dynamicSize)
    {
    }

protected:
    const char *staticData;
    const char *dynamicData;
    const SerializedData::hel dynamicSize;
};

#include "Any.h"
#include "Plain.h"
#include "Vector.h"
#include "VectorOfAny.h"
#include "Last.h"
#include "Void.h"
//#include "AnyOf.h"
