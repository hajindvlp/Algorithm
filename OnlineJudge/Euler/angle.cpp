#include <stdio.h>



/* ----------------------------------------------------------------------------



struct POINT : A point (x, y)



---------------------------------------------------------------------------- */

typedef struct tagPOINT

{

        int x;

        int y;

} POINT;



/* ----------------------------------------------------------------------------



struct LINE : A line with two POINTs a, b



---------------------------------------------------------------------------- */

typedef struct tagLINE

{

        POINT a;

        POINT b;

} LINE;



/* ----------------------------------------------------------------------------



Name           : SwapPoints

Function       : Swap two points

Parameters     :

        POINT *a, *b   - Points will be swapped

Return         :

        0       - Normal



---------------------------------------------------------------------------- */

int SwapPoints(POINT *a, POINT *b);



/* ----------------------------------------------------------------------------



Name           : PointsDir

Function       : Tell the direction of three points

Parameters     :

        POINT a, b, c  - Three points

Return         :

        1              - Clockwise

        -1             - Count-clockwise

        0              - Three points are on the same line



---------------------------------------------------------------------------- */

int PointsDir(POINT a, POINT b, POINT c);



/* ----------------------------------------------------------------------------



Name           : IsCrossed

Function       : Check if two lines are crossed

Parameters     :

        LINE l1, l2 - Two lines

Return         :

        1       - Crossed

        0       - One line contains other line's point

        -1      - Not crossed



---------------------------------------------------------------------------- */

int IsCrossed(LINE l1, LINE l2);



int main()

{

        POINT a = { 1, 1 };

        POINT b = { 5, 5 };

        POINT c = { 2, 1 };

        POINT d = { 4, -1 };



        LINE l1 = { a, b };

        LINE l2 = { c, d };



        int ret = IsCrossed(l1, l2);



        if ( ret == 1 )

               printf("Crossed\n");

        else if ( ret == -1 )

               printf("Not crossed\n");

        else

               printf("One line contains other line's point\n");



        return 0;

}



int SwapPoints(POINT *a, POINT *b)

{

        POINT tmp;



        tmp.x = a->x;

        tmp.y = a->y;



        a->x = b->x;

        a->y = b->y;



        b->x = tmp.x;

        b->y = tmp.y;



        return 0;

}



int PointsDir(POINT a, POINT b, POINT c)

{

        int cross = b.x * c.y - a.y * b.x - a.x * c.y

               - b.y * c.x + a.x * b.y + a.y * c.x;



        if ( cross > 0 )

               return 1;

        else if ( cross < 0 )

               return -1;

        else

               return 0;

}



int IsCrossed(LINE l1, LINE l2)

{

        int p123, p124, p341, p342;



        if ( l1.a.x > l1.b.x )

               SwapPoints(&l1.a, &l1.b);



        if ( l2.a.x > l2.b.x )

               SwapPoints(&l2.a, &l2.b);



        p123 = PointsDir(l1.a, l1.b, l2.a);

        p124 = PointsDir(l1.a, l1.b, l2.b);

        p341 = PointsDir(l2.a, l2.b, l1.a);

        p342 = PointsDir(l2.a, l2.b, l1.b);



        if ( p123 * p124 < 0 && p341 * p342 < 0 )

               return 1;

        if ( p123 == 0 && p124 == 0 )

        {

               if ( !( l2.a.x > l1.b.x || l1.a.x > l2.b.x ) )

                       return 0;

               else

                       return -1;

        }

        if ( p123 == 0 )

        {

               if ( l1.a.x <= l2.a.x && l2.a.x <= l1.b.x )

                       return 0;

               else

                       return -1;

        }

        if ( p124 == 0 )

        {

               if ( l1.a.x <= l2.b.x && l2.b.x <= l1.b.x )

                       return 0;

               else

                       return -1;

        }

        if ( p341 == 0 )

        {

               if ( l2.a.x <= l1.a.x && l1.a.x <= l2.b.x )

                       return 0;

               else

                       return -1;

        }

        if ( p342 == 0 )

        {

               if ( l2.a.x <= l1.b.x && l1.b.x <= l2.b.x )

                       return 0;

               else

                       return -1;

        }



        return -1;

}


[출처] 두 선분의 교차 여부를 알아 내는 알고리즘|작성자 eddie
