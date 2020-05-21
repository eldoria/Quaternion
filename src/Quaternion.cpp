#include "Quaternion.h"
#include <math.h>

#define square(x) x * x

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


void Quaternion::normaliser(){
    float norm = norme();

    _x /= norm;
    _y /= norm;
    _z /= norm;
    _w /= norm;
}

Quaternion Quaternion::soustraction(Quaternion Q1, Quaternion Q2){
    /// fait la soustraction du premier quaternion avec le deuxième et retourne le résultat sous la forme d'un nouveau quaternion
    float x = Q1.getX() - Q2.getX();
    float y = Q1.getY() - Q2.getY();
    float z = Q1.getZ() - Q2.getZ();
    float w = Q1.getW() - Q2.getW();

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::addition(Quaternion Q1, Quaternion Q2){
    /// aditionne 2 quaternions et retourne le résultat sous la forme d'un nouveau quaternion
    float x = Q1.getX() + Q2.getX();
    float y = Q1.getY() + Q2.getY();
    float z = Q1.getZ() + Q2.getZ();
    float w = Q1.getW() + Q2.getW();

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::multiplication(Quaternion Q1, Quaternion Q2){
    /// multiplie 2 quaternions et retourne le résultat sous la forme d'un nouveau quaternion
    float x = (Q1.getY() * Q2.getZ()) - (Q1.getZ() * Q2.getY()) + (Q2.getW() * Q1.getX()) + (Q1.getW() * Q2.getX());
    float y = (Q1.getZ() * Q2.getX()) - (Q1.getX() * Q2.getZ()) + (Q2.getW() * Q1.getY()) + (Q1.getW() * Q2.getY());
    float z = (Q1.getX() * Q2.getY()) - (Q1.getY() * Q2.getX()) + (Q2.getW() * Q1.getZ()) + (Q1.getW() * Q2.getZ());
    float w = (Q1.getW() * Q2.getW()) - (Q1.getX() * Q2.getX()) - (Q1.getY() * Q2.getY()) - (Q1.getZ() * Q2.getZ());

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::conjugue(Quaternion Q) {
    return Quaternion(-Q.getX(),-Q.getY(),-Q.getZ(),Q.getW());

}
