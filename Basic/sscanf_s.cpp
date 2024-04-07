#include <iostream>
#include <string>
#include <sstream>

int main()
{
//    BEIDOU_M1
// 1 31115U 07011A   18006.18187596 -.00000074 +00000-0 +00000-0 0  9992
// 2 31115 053.0848 321.1223 0003055 291.0391 068.9263 01.77348172021459
std::string Line_2("2 31115 053.0848 321.1223 0003055 291.0391 068.9263 01.77348172021459");
double dInclination,dAscendingNode,dEccentricity,dArgumentoOfPerigee,dMeanAnomaly,dMeanMotion;
char cEccentricity[8];
 sscanf_s(Line_2.c_str(), "%*s%*s%lf%lf%s%lf%lf%lf",&dInclination
          ,&dAscendingNode
          ,cEccentricity,8
          ,&dArgumentoOfPerigee
          ,&dMeanAnomaly
          ,&dMeanMotion);
std::stringstream ss;
ss<<"0."<<cEccentricity;
ss>>dEccentricity;
          //
            //           Line_2.c_str(): 要解析的字符串。
            // "%*s%*s%lf%lf%s%lf%lf%lf": 解析字符串的格式控制符。其中 %*s 表示跳过一个字符串（即不保存该数据），%lf 表示解析一个 double 类型的数值，%s 表示解析一个字符串。
            // &dInclination: 解析得到的倾角数据将存储到 dInclination 变量中。
            // &dAscendingNode: 解析得到的升交点经度数据将存储到 dAscendingNode 变量中。
            // cEccentricity,8: 解析得到的离心率字符串将存储到 cEccentricity 数组中，数组大小为 8。
            // &dArgumentoOfPerigee: 解析得到的近地点幅角数据将存储到 dArgumentoOfPerigee 变量中。
            // &dMeanAnomaly: 解析得到的平近点角数据将存储到 dMeanAnomaly 变量中。
            // &dMeanMotion: 解析得到的平均运动数据将存储到 dMeanMotion 变量中。
          //

              return 0;
}