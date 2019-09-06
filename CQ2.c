#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

JNIEXPORT jintArray JNICALL Java_Q2_randomArr(JNIEnv *env, jobject obj, jint size) {
    time_t t;
    // seed random, for random function random int every execution
    srand((unsigned) time(&t));

    // Create new jintArray
    jintArray result = (*env)->NewIntArray(env, size);
    if (result == NULL) { // if creation failed because out of memory
        return NULL; // return null array
    }
    // create jint array
    jint fill[size];
    // Count the number which is less than 50 in the array
    int count = 0;
    for (int i = 0; i < size; i++) {
        // random modulus 100, 0 to 99, + 1 make it 100
        fill[i] = rand() % 100 + 1;
        if (fill[i] < 50) {
            count++;
        }
        printf("%ld ", fill[i]);
    }
    printf("\nNumber less than 50 in array: %d\n", count);
    // copy the whole fill array into result array.
    (*env)->SetIntArrayRegion(env, result, 0, size, fill);
    return result;
}

JNIEXPORT jint JNICALL Java_Q2_calcDiff(JNIEnv *env, jobject obj, jintArray arr) {
    // get the jintarray into jint array
    jint *inArr = (*env)->GetIntArrayElements(env, arr, NULL);
    if (inArr == NULL) { // out of memory
        return 0;
    }
    // get the size of the jintarray
    jsize size = (*env)->GetArrayLength(env, arr);
    // declare and initialize min and max variable
    jint min = inArr[0];
    jint max = inArr[0];
    // look for min and max number in array
    for (int i = 0; i < size; i++) {
        if (min > inArr[i]) {
            min = inArr[i];
        }
        if (max < inArr[i]) {
            max = inArr[i];
        }
    }
    // return the difference
    return (max - min);
}