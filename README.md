# thir

s **T** ructurized
s **H** ema-full
b **I** nary
p **R** otocol

![Travis-CI](https://travis-ci.org/tz-lom/thir.svg?branch=master)

# What is it
It's a C++ library for definition binary serialization schema which creates fast compact and predictable binary fragments, which can be easily readed and created using C++ classes.
The library supports C++98 and newer and have only Boost headers in dependencies. The library itself have no linking objects and can be used in header or in header and .cpp file.
The library depends from the following Boost components:
* boost/preprocessor
* boost/endian
* boost/shared_ptr [ if used compiler before C++11]
All these libraries are header-only.


# Storage format

@startditaa

                       +---------------+-------------+--------------+
                       | Dynamic sizes | Static data | Dynamic data |
                  +----+               |             |              |
                  | ID |  hel  |  hel  |  F1  |  F3  | F2[] | F3[]  |
                  +----+-------+-------+------+------+------+-------+
                           ^       ^       ^      ^      ^     ^
                           |       |       |      |      |     |
+--------+                 :       :       :      :      :     :
| F1 int | -------=------------------------+      |      |     |
+--------+                 |       |              |      |     |
                           |       |              |      |     |
+----------+               :       :              |      |     |
| F2 int[] | ----=---------*-----------------------------+     |
+----------+                       |              |            |
                                   |              |            |
+----------------+                 |              |            |
| F3 bool+char[] | ----------------*--------------*------------+
+----------------+


@endditaa


License
----
MIT
