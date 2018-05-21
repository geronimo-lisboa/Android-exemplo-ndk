#include <jni.h>
#include <string>
#include <memory>
#include <iostream>
using namespace std;
/**
 * Minha classe de teste.
 * */
class HelloCpp{
public:
    HelloCpp(){
        cout<<"Construtor"<<endl;
    }
    ~HelloCpp(){
        cout<<"Destrutor"<<endl;
    }
};
/**Uma vez que esse shared_ptr é atribuído ele vive para sempre... ele terá que ser desalocado manualmente.*/
shared_ptr<HelloCpp> testeMem = nullptr;

extern "C" JNIEXPORT jstring

JNICALL
Java_dongeronimo_com_simcity_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    if(!testeMem){
        std::string hello = "O objeto nao está criado";
        testeMem = make_shared<HelloCpp>();
        return env->NewStringUTF(hello.c_str());
    }else{
        std::string hello = "O objeto está criado";
        return env->NewStringUTF(hello.c_str());
    }

}
