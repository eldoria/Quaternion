#ifndef QUATERNION_H
#define QUATERNION_H


class Quaternion
{
    public:
        Quaternion(float x, float y, float z, float w);

        soustraction(Quaternion Q1, Quaternion Q2);
        addition(Quaternion Q1, Quaternion Q2);
        multiplication(Quaternion Q1, Quaternion Q2);
        conjugue(Quaternion Q);
        norme(Quaternion Q);

    protected:

    private:
};

#endif // QUATERNION_H
