#include <jni.h>
#include <stdio.h>
#include <string.h>

JNIEXPORT void JNICALL Java_Q1_calcDiloma(JNIEnv *env, jobject obj, jdouble cgpa) {
    // declare Classification of Honours variable, default is "failed"
    char coh[12] = "Failed";
    // cgpa logic, strcpy copy string into coh
    if (cgpa >= 3.5 && cgpa <= 4.00) {
        strcpy(coh, "Distinction");
    } else if (cgpa >= 3.0 && cgpa <= 3.49) {
        strcpy(coh, "Credit");
    } else if (cgpa >= 2.0 && cgpa <= 2.99) {
        strcpy(coh, "Pass");
    }
    // %0.2f print double with 2 decimal place
    printf("CGPA: %0.2f\nYour Classification of Honours: %s\n", cgpa, coh);
}


JNIEXPORT void JNICALL Java_Q1_calcDegree(JNIEnv *env, jobject obj, jdouble cgpa) {
    // declare Classification of Honours variable, default is "failed"
    char coh[13] = "Failed";
    // cgpa logic, strcpy copy string into coh
    if (cgpa >= 3.67 && cgpa <= 4.00) {
        strcpy(coh, "First");
    } else if (cgpa >= 3.33 && cgpa <= 3.66) {
        strcpy(coh, "Second Upper");
    } else if (cgpa >= 2.67 && cgpa <= 3.32) {
        strcpy(coh, "Second Lower");
    } else if (cgpa >= 2.0 && cgpa <= 2.66) {
        strcpy(coh, "Third");
    }
    // %0.2f print double with 2 decimal place
    printf("CGPA: %0.2f\nYour Classification of Honours: %s\n", cgpa, coh);
}