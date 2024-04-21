#ifndef FIREBASE_H
#define FIREBASE_H

// Replace with your Firebase project credentials
#define FIREBASE_HOST "weatherstation-39665-default-rtdb.firebaseio.com"                //"your-firebase-project.firebaseio.com"
#define FIREBASE_AUTH "MXXCXSCfQ4Zu6ob2mgGSaIEds3EONgg20aQhIrsI"                                                           //"your-firebase-auth-token"

// Function prototypes
void setupFirebase();
void sendDataToFirebase(float humidity, float temperature);

#endif