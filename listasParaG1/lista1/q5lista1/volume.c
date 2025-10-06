#include "volume.h"
#define PI 3.14

float volume_esfera(float r){
    return 4/3 * PI * r * r * r;
}

float volume_cone (float r, float h){
    return (PI * r * r * h)/3.0f ;
}

float volume_cubo(float l){
    return l * l * l;
}