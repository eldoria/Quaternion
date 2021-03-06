#include "Quaternion.h"
#include <math.h>

#define square(x) x * x
#define n 3

Quaternion::Quaternion(float x, float y, float z, float w)
{
    _x = x;
    _y = y;
    _z = z;
    _w = w;
}

float Quaternion::getX(){
    return _x;
}

float Quaternion::getY(){
    return _y;
}

float Quaternion::getZ(){
    return _z;
}

float Quaternion::getW(){
    return _w;
}


float Quaternion::norme(){
    return sqrt(square(_x) + square(_y) + square(_z) + square(_w));
}


float* Quaternion::QuaternionToMatrix(){
    float* matrix = new float[3*3];

    matrix[0] = 1 - 2 * square(this->getY()) - 2 * square(this->getZ());
    matrix[1] = 2 * this->getX() * this->getY() - 2 * this->getZ() * this->getW();
    matrix[2] = 2 * this->getX() * this->getZ() + 2 * this->getY() * this->getW();

    matrix[3] = 2 * this->getX() * this->getY() + 2 * this->getZ() * this->getW();
    matrix[4] = 1 - 2 * square(this->getX()) - 2 * square(this->getZ());
    matrix[5] = 2 * this->getY() * this->getZ() - 2 * this->getX() * this->getW();

    matrix[6] = 2 * this->getX() * this->getZ() - 2 * this->getY() * this->getW();
    matrix[7] = 2 * this->getY() * this->getZ() + 2 * this->getX() * this->getW();
    matrix[8] = 1 - 2 * square(this->getX()) - 2 * square(this->getY());

    return matrix;
}


Quaternion Quaternion::MatrixToQuaternion(float* matrix){
    float tr = matrix[0] + matrix[4] + matrix[8];

    float x,y,z,w,S;

    if (tr > 0){
        S = sqrt(tr + 1.0) * 2;
        w = 0.25 * S;
        x = (matrix[7] - matrix[5]) / S;
        y = (matrix[2] - matrix[6]) / S;
        z = (matrix[3] - matrix[1]) / S;
    }
    else if((matrix[0] > matrix[4])&(matrix[0] > matrix[8])){
        S = sqrt(1 + matrix[0] - matrix[4] - matrix[8]) * 2;
        w = (matrix[7] - matrix[5]) / S;
        x = 0.25 * S;
        y = (matrix[1] * matrix[3]) / S;
        z = (matrix[2] * matrix[6]) / S;
    }
    else if (matrix[4] > matrix[8]){
        S = sqrt(1.0 + matrix[4] - matrix[0] - matrix[8]) * 2;
        w = (matrix[2] - matrix[6]) / S;
        x = (matrix[1] + matrix[3]) / S;
        y = 0.25 * S;
        z = (matrix[5] + matrix[7]) / S;
    }
    else{
        S = sqrt(1.0 + matrix[8] - matrix[0] - matrix[4]) * 2;
        w = (matrix[3] - matrix[1]) / S;
        x = (matrix[2] + matrix[6]) / S;
        y = (matrix[5] + matrix[7]) / S;
        z = 0.25 * S;
    }
    return Quaternion(w,x,y,z);
}


void Quaternion::normaliser(){
    float norm = norme();

    _x /= norm;
    _y /= norm;
    _z /= norm;
    _w /= norm;
}

Quaternion Quaternion::soustraction(Quaternion Q1, Quaternion Q2){
    /// fait la soustraction du premier quaternion avec le deuxi�me et retourne le r�sultat sous la forme d'un nouveau quaternion
    float x = Q1.getX() - Q2.getX();
    float y = Q1.getY() - Q2.getY();
    float z = Q1.getZ() - Q2.getZ();
    float w = Q1.getW() - Q2.getW();

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::addition(Quaternion Q1, Quaternion Q2){
    /// aditionne 2 quaternions et retourne le r�sultat sous la forme d'un nouveau quaternion
    float x = Q1.getX() + Q2.getX();
    float y = Q1.getY() + Q2.getY();
    float z = Q1.getZ() + Q2.getZ();
    float w = Q1.getW() + Q2.getW();

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::multiplication(Quaternion Q1, Quaternion Q2){
    /// multiplie 2 quaternions et retourne le r�sultat sous la forme d'un nouveau quaternion
    float x = (Q1.getY() * Q2.getZ()) - (Q1.getZ() * Q2.getY()) + (Q2.getW() * Q1.getX()) + (Q1.getW() * Q2.getX());
    float y = (Q1.getZ() * Q2.getX()) - (Q1.getX() * Q2.getZ()) + (Q2.getW() * Q1.getY()) + (Q1.getW() * Q2.getY());
    float z = (Q1.getX() * Q2.getY()) - (Q1.getY() * Q2.getX()) + (Q2.getW() * Q1.getZ()) + (Q1.getW() * Q2.getZ());
    float w = (Q1.getW() * Q2.getW()) - (Q1.getX() * Q2.getX()) - (Q1.getY() * Q2.getY()) - (Q1.getZ() * Q2.getZ());

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::conjugue(Quaternion Q) {
    return Quaternion(-Q.getX(),-Q.getY(),-Q.getZ(),Q.getW());

}

int Quaternion::Dotproduct(int vect1[],int vect2[]){
    ///retourne le produit scalaire 2 vecteur

    int product = 0;
    for (int i = 0; i<n; i++)
        product = product+vect1[i]*vect2[i];
    return product;


}

int Quaternion::Crossproduct(int vect1[],int vect2[]){
    ///retourne le produit vectoriel 2 vecteur

    int x = (vect1[1]*vect2[2]-vect1[2]*vect2[1]);
    int y = (vect1[0]*vect2[2]-vect1[2]*vect2[0]);
    int z = (vect1[0]*vect2[1]-vect1[1]*vect2[0]);
    int scal = (x, y, z);
    return scal;

}
