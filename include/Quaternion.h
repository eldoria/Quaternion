#ifndef QUATERNION_H
#define QUATERNION_H


class Quaternion
{
    public:
        Quaternion(float x, float y, float z, float w);

        float getX();
        float getY();
        float getZ();
        float getW();

        float norme();
        void normaliser();

        float* QuaternionToMatrix();

        Quaternion soustraction(Quaternion Q1, Quaternion Q2);
        Quaternion addition(Quaternion Q1, Quaternion Q2);
        Quaternion multiplication(Quaternion Q1, Quaternion Q2);
        Quaternion conjugue(Quaternion Q);

    protected:

    private:
        float _x;
        float _y;
        float _z;
        float _w;
};

#endif // QUATERNION_H
