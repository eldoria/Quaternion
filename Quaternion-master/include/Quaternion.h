#ifndef QUATERNION_H
#define QUATERNION_H


class Quaternion
{
    public:
        Quaternion(float x, float y, float z, float w);

        Quaternion soustraction(Quaternion Q1, Quaternion Q2);
        Quaternion addition(Quaternion Q1, Quaternion Q2);
        Quaternion multiplication(Quaternion Q1, Quaternion Q2);
        Quaternion conjugue(Quaternion Q);
        float norme(Quaternion Q);

    protected:

    private:
        float _x;
        float _y;
        float _z;
        float _w;
};

#endif // QUATERNION_H
