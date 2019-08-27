#define STRICT

#include <stdlib.h>
#include <NIDAQmx.h>

#include "Util.h"

uInt64 toUInt64(jobject value){

}

jobject toBigInteger(uInt64 value){

}

const char *getStringUTFChars(JNIEnv *env, jstring jstr, jboolean *isCopy) {
	const char *str = NULL;

	if (jstr != NULL) {
		str = (*env)->GetStringUTFChars(env, jstr, isCopy);
	}

	return str;
}

void throwNIDAQmxJWrapperException(JNIEnv *env, int32 code) {
	int32 bufferSize;
	char *error = NULL;
	jclass class = NULL;
	jstring jerror = NULL;
	jmethodID constructor = NULL;
	jobject exception = NULL;

	bufferSize = DAQmxGetExtendedErrorInfo(NULL, 0);

	error = (char *) malloc(bufferSize);

	// Se o bufferSize for diferente de 0 então há informação sobre o erro
	if (bufferSize != 0) {

		// Todas as funções referentes a interface DAQmx devem ter tratamento de
		// erros, porém nesse caso não foi implementado pois poderia entrar
		// num loop
		DAQmxGetExtendedErrorInfo(error, bufferSize);

		jerror = (*env)->NewStringUTF(env, error);
	}

	// Procura a classe referente a exceção a ser disparada
	class = (*env)->FindClass(env, "com/wrapper/NIDAQmxJWrapperException");
	if (class == NULL) {
		printf("\n\n****** ERROR THROWING EXCEPTION *****");

		return;
	}

	constructor = (*env)->GetMethodID(env, class, "<init>",
			"(ILjava/lang/String;)V");
	exception = (*env)->NewObject(env, class, constructor, code, jerror);

	// Dispara a exceção
	(*env)->Throw(env, exception);

	(*env)->ReleaseStringUTFChars(env, jerror, error);
	(*env)->DeleteLocalRef(env, class);
	(*env)->DeleteLocalRef(env, exception);
}

