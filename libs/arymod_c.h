#ifndef _MY_PACKAGE_FOO_H_
#define _MY_PACKAGE_FOO_H_
typedef void* Mod;

#ifdef __cplusplus
extern "C" {
#endif

Mod Mod_construct(float a_);
void Mod_destruct(Mod id);

void SetA(Mod id, float a_);
void Add(Mod id, float *in_, int length, float *out_);
void AddSleep(Mod id, float *in_, int length, float *out_, int usec);
void Multi(Mod id, float *in_, int length, float *out_);


#ifdef __cplusplus
}
#endif

#endif
