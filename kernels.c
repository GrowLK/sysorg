/********************************************************
 * Kernels to be optimized for the CSO Final Exam
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "team",              /* Team name */
    "Yimo Han",     /* First member full name */
    "yh2790@nyu.edu",         /* First member email address */
    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: optimized version1-- loop unrolling";
void rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    if(dim < 32){
        naive_rotate(dim, src, dst);
    }else{

        for (i = 0; i < dim; i++){
            for (j = 0; j < dim -1 ; j+=16){
                dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
                dst[RIDX(dim-1-j-1, i, dim)] = src[RIDX(i, j+1, dim)];
                dst[RIDX(dim-1-j-2, i, dim)] = src[RIDX(i, j+2, dim)];
                dst[RIDX(dim-1-j-3, i, dim)] = src[RIDX(i, j+3, dim)];
                dst[RIDX(dim-1-j-4, i, dim)] = src[RIDX(i, j+4, dim)];
                dst[RIDX(dim-1-j-5, i, dim)] = src[RIDX(i, j+5, dim)];
                dst[RIDX(dim-1-j-6, i, dim)] = src[RIDX(i, j+6, dim)];
                dst[RIDX(dim-1-j-7, i, dim)] = src[RIDX(i, j+7, dim)];
                dst[RIDX(dim-1-j-8, i, dim)] = src[RIDX(i, j+8, dim)];
                dst[RIDX(dim-1-j-9, i, dim)] = src[RIDX(i, j+9, dim)];
                dst[RIDX(dim-1-j-10, i, dim)] = src[RIDX(i, j+10, dim)];
                dst[RIDX(dim-1-j-11, i, dim)] = src[RIDX(i, j+11, dim)];
                dst[RIDX(dim-1-j-12, i, dim)] = src[RIDX(i, j+12, dim)];
                dst[RIDX(dim-1-j-13, i, dim)] = src[RIDX(i, j+13, dim)];
                dst[RIDX(dim-1-j-14, i, dim)] = src[RIDX(i, j+14, dim)];
                dst[RIDX(dim-1-j-15, i, dim)] = src[RIDX(i, j+15, dim)];
            }

            if(j < dim){
                dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
            }
    
        }

    }

    
    
}

char rotate_descr1[] = "rotate: optimized version2-- blocking";
void rotate1(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    if(dim < 32){
        naive_rotate(dim, src, dst);
    }else{
        int m, n;
        int size=16;

        for (i = 0; i < dim; i+=size){
           for (j = 0; j < dim; j+=size){
               for(m = i; m < i + size; m++){
                  for(n = j; n < j + size; n++){
                    dst[RIDX(dim-1-n, m, dim)] = src[RIDX(m, n, dim)];
                  }
               }
               
           }
        }
    }
}

char rotate_descr2[] = "rotate: optimized version3-- blocking";
void rotate2(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    if (src==dst )
    {
        naive_rotate(dim, src, dst);
        return;
    }
    for (i = 0; i < dim; i+=4)
	    for (j = 0; j < dim; j+=4)
        {
            dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
            dst[RIDX(dim-2-j, i, dim)] = src[RIDX(i, j+1, dim)];
            dst[RIDX(dim-3-j, i, dim)] = src[RIDX(i, j+2, dim)];
            dst[RIDX(dim-4-j, i, dim)] = src[RIDX(i, j+3, dim)];
            dst[RIDX(dim-4-j, i+1, dim)] = src[RIDX(i+1, j+3, dim)];
            dst[RIDX(dim-3-j, i+1, dim)] = src[RIDX(i+1, j+2, dim)];
            dst[RIDX(dim-2-j, i+1, dim)] = src[RIDX(i+1, j+1, dim)];
            dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];

            dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
            dst[RIDX(dim-2-j, i+2, dim)] = src[RIDX(i+2, j+1, dim)];
            dst[RIDX(dim-3-j, i+2, dim)] = src[RIDX(i+2, j+2, dim)];
            dst[RIDX(dim-4-j, i+2, dim)] = src[RIDX(i+2, j+3, dim)];
            dst[RIDX(dim-4-j, i+3, dim)] = src[RIDX(i+3, j+3, dim)];
            dst[RIDX(dim-3-j, i+3, dim)] = src[RIDX(i+3, j+2, dim)];
            dst[RIDX(dim-2-j, i+3, dim)] = src[RIDX(i+3, j+1, dim)];
            dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
        }
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    //add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);  
    add_rotate_function(&rotate1, rotate_descr1); 
    add_rotate_function(&rotate2, rotate_descr2); 
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg_split(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    if(i == 0 ){
        for(ii = 0; ii <= 1; ii++) 
        for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);
    } else if( i == dim -1) {
        for(ii = max(i-1, 0); ii <= dim-1; ii++)
        for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);
    } else if( j == 0) {
        for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++)
        for(jj = 0; jj <= 1; jj++)
            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);
    } else if( j == dim -1) {
        for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++)
        for(jj = max(j-1, 0); jj <= dim-1; jj++)
            accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);
    } else{
        for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
        for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);
    }
  

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: optimized version1-- split";
void smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
        dst[RIDX(i, j, dim)] = avg_split(dim, i, j, src);
    
}

char smooth_descr1[] = "smooth: optimized version2-- loop unrolling";
void smooth1(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    for (i = 0; i < dim; i++){
            for (j = 0; j < dim -1 ; j+=16){
                dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
                dst[RIDX(i, j+1, dim)] = avg(dim, i, j+1, src);
                dst[RIDX(i, j+2, dim)] = avg(dim, i, j+2, src);
                dst[RIDX(i, j+3, dim)] = avg(dim, i, j+3, src);
                dst[RIDX(i, j+4, dim)] = avg(dim, i, j+4, src);
                dst[RIDX(i, j+5, dim)] = avg(dim, i, j+5, src);
                dst[RIDX(i, j+6, dim)] = avg(dim, i, j+6, src);
                dst[RIDX(i, j+7, dim)] = avg(dim, i, j+7, src);
                dst[RIDX(i, j+8, dim)] = avg(dim, i, j+8, src);
                dst[RIDX(i, j+9, dim)] = avg(dim, i, j+9, src);
                dst[RIDX(i, j+10, dim)] = avg(dim, i, j+10, src);
                dst[RIDX(i, j+11, dim)] = avg(dim, i, j+11, src);
                dst[RIDX(i, j+12, dim)] = avg(dim, i, j+12, src);
                dst[RIDX(i, j+13, dim)] = avg(dim, i, j+13, src);
                dst[RIDX(i, j+14, dim)] = avg(dim, i, j+14, src);
                dst[RIDX(i, j+15, dim)] = avg(dim, i, j+15, src);
            }

            if(j < dim){
               dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
            }
    
        }
}

char smooth_descr2[] = "smooth: optimized version3-- reduce function calls";
void smooth2(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    if (src==dst )
    {
        naive_smooth(dim, src, dst);
        return;
    }
    dst[RIDX(0, 0, dim)].red = (src[RIDX(0, 0, dim)].red+src[RIDX(0, 1, dim)].red+src[RIDX(1, 1, dim)].red+src[RIDX(1, 0, dim)].red)/4;
    dst[RIDX(0, 0, dim)].green = (src[RIDX(0, 0, dim)].green+src[RIDX(0, 1, dim)].green+src[RIDX(1, 1, dim)].green+src[RIDX(1, 0, dim)].green)/4;
    dst[RIDX(0, 0, dim)].blue = (src[RIDX(0, 0, dim)].blue+src[RIDX(0, 1, dim)].blue+src[RIDX(1, 1, dim)].blue+src[RIDX(1, 0, dim)].blue)/4;

    dst[RIDX(0, dim-1, dim)].red = (src[RIDX(0, dim-1, dim)].red+src[RIDX(1, dim-1, dim)].red+src[RIDX(1, dim-2, dim)].red+src[RIDX(0, dim-2, dim)].red)/4;
    dst[RIDX(0, dim-1, dim)].green = (src[RIDX(0, dim-1, dim)].green+src[RIDX(1, dim-1, dim)].green+src[RIDX(1, dim-2, dim)].green+src[RIDX(0, dim-2, dim)].green)/4;
    dst[RIDX(0, dim-1, dim)].blue = (src[RIDX(0, dim-1, dim)].blue+src[RIDX(1, dim-1, dim)].blue+src[RIDX(1, dim-2, dim)].blue+src[RIDX(0, dim-2, dim)].blue)/4;

    dst[RIDX(dim-1, 0, dim)].red = (src[RIDX(dim-1, 0, dim)].red+src[RIDX(dim-2, 0, dim)].red+src[RIDX(dim-2, 1, dim)].red+src[RIDX(dim-1, 1, dim)].red)/4;
    dst[RIDX(dim-1, 0, dim)].green = (src[RIDX(dim-1, 0, dim)].green+src[RIDX(dim-2, 0, dim)].green+src[RIDX(dim-2, 1, dim)].green+src[RIDX(dim-1, 1, dim)].green)/4;
    dst[RIDX(dim-1, 0, dim)].blue = (src[RIDX(dim-1, 0, dim)].blue+src[RIDX(dim-2, 0, dim)].blue+src[RIDX(dim-2, 1, dim)].blue+src[RIDX(dim-1, 1, dim)].blue)/4;

    dst[RIDX(dim-1, dim-1, dim)].red = (src[RIDX(dim-1, dim-1, dim)].red+src[RIDX(dim-1, dim-2, dim)].red+src[RIDX(dim-2, dim-2, dim)].red+src[RIDX(dim-2, dim-1, dim)].red)/4;
    dst[RIDX(dim-1, dim-1, dim)].green = (src[RIDX(dim-1, dim-1, dim)].green+src[RIDX(dim-1, dim-2, dim)].green+src[RIDX(dim-2, dim-2, dim)].green+src[RIDX(dim-2, dim-1, dim)].green)/4;
    dst[RIDX(dim-1, dim-1, dim)].blue = (src[RIDX(dim-1, dim-1, dim)].blue+src[RIDX(dim-1, dim-2, dim)].blue+src[RIDX(dim-2, dim-2, dim)].blue+src[RIDX(dim-2, dim-1, dim)].blue)/4;
    for (i = 1; i < dim-1; i++)
    {
        dst[RIDX(i, 0, dim)].red = (src[RIDX(i-1, 0, dim)].red+src[RIDX(i-1, 1, dim)].red+src[RIDX(i, 1, dim)].red+src[RIDX(i, 0, dim)].red+src[RIDX(i+1, 0, dim)].red+src[RIDX(i+1, 1, dim)].red)/6;
        dst[RIDX(i, 0, dim)].green = (src[RIDX(i-1, 0, dim)].green+src[RIDX(i-1, 1, dim)].green+src[RIDX(i, 1, dim)].green+src[RIDX(i, 0, dim)].green+src[RIDX(i+1, 0, dim)].green+src[RIDX(i+1, 1, dim)].green)/6;
        dst[RIDX(i, 0, dim)].blue = (src[RIDX(i-1, 0, dim)].blue+src[RIDX(i-1, 1, dim)].blue+src[RIDX(i, 1, dim)].blue+src[RIDX(i, 0, dim)].blue+src[RIDX(i+1, 0, dim)].blue+src[RIDX(i+1, 1, dim)].blue)/6;

        dst[RIDX(i, dim-1, dim)].red = (src[RIDX(i-1, dim-1, dim)].red+src[RIDX(i-1, dim-2, dim)].red+src[RIDX(i, dim-2, dim)].red+src[RIDX(i, dim-1, dim)].red+src[RIDX(i+1, dim-1, dim)].red+src[RIDX(i+1, dim-2, dim)].red)/6;
        dst[RIDX(i, dim-1, dim)].green = (src[RIDX(i-1, dim-1, dim)].green+src[RIDX(i-1, dim-2, dim)].green+src[RIDX(i, dim-2, dim)].green+src[RIDX(i, dim-1, dim)].green+src[RIDX(i+1, dim-1, dim)].green+src[RIDX(i+1, dim-2, dim)].green)/6;
        dst[RIDX(i, dim-1, dim)].blue = (src[RIDX(i-1, dim-1, dim)].blue+src[RIDX(i-1, dim-2, dim)].blue+src[RIDX(i, dim-2, dim)].blue+src[RIDX(i, dim-1, dim)].blue+src[RIDX(i+1, dim-1, dim)].blue+src[RIDX(i+1, dim-2, dim)].blue)/6;

        dst[RIDX(0, i, dim)].red = (src[RIDX(0, i-1, dim)].red+src[RIDX(0, i, dim)].red+src[RIDX(0, i+1, dim)].red+src[RIDX(1, i+1, dim)].red+src[RIDX(1, i, dim)].red+src[RIDX(1, i-1, dim)].red)/6;
        dst[RIDX(0, i, dim)].green = (src[RIDX(0, i-1, dim)].green+src[RIDX(0, i, dim)].green+src[RIDX(0, i+1, dim)].green+src[RIDX(1, i+1, dim)].green+src[RIDX(1, i, dim)].green+src[RIDX(1, i-1, dim)].green)/6;
        dst[RIDX(0, i, dim)].blue = (src[RIDX(0, i-1, dim)].blue+src[RIDX(0, i, dim)].blue+src[RIDX(0, i+1, dim)].blue+src[RIDX(1, i+1, dim)].blue+src[RIDX(1, i, dim)].blue+src[RIDX(1, i-1, dim)].blue)/6;

        dst[RIDX(dim-1, i, dim)].red = (src[RIDX(dim-1, i-1, dim)].red+src[RIDX(dim-1, i, dim)].red+src[RIDX(dim-1, i+1, dim)].red+src[RIDX(dim-2, i+1, dim)].red+src[RIDX(dim-2, i, dim)].red+src[RIDX(dim-2, i-1, dim)].red)/6;
        dst[RIDX(dim-1, i, dim)].green = (src[RIDX(dim-1, i-1, dim)].green+src[RIDX(dim-1, i, dim)].green+src[RIDX(dim-1, i+1, dim)].green+src[RIDX(dim-2, i+1, dim)].green+src[RIDX(dim-2, i, dim)].green+src[RIDX(dim-2, i-1, dim)].green)/6;
        dst[RIDX(dim-1, i, dim)].blue = (src[RIDX(dim-1, i-1, dim)].blue+src[RIDX(dim-1, i, dim)].blue+src[RIDX(dim-1, i+1, dim)].blue+src[RIDX(dim-2, i+1, dim)].blue+src[RIDX(dim-2, i, dim)].blue+src[RIDX(dim-2, i-1, dim)].blue)/6;
	    for (j = 1; j < dim-1; j++)
        {
            dst[RIDX(i, j, dim)].red = (src[RIDX(i-1, j-1, dim)].red+src[RIDX(i-1, j, dim)].red+src[RIDX(i-1, j+1, dim)].red+src[RIDX(i, j+1, dim)].red+src[RIDX(i, j, dim)].red+src[RIDX(i, j-1, dim)].red+src[RIDX(i+1, j-1, dim)].red+src[RIDX(i+1, j, dim)].red+src[RIDX(i+1, j+1, dim)].red)/9;
            dst[RIDX(i, j, dim)].green = (src[RIDX(i-1, j-1, dim)].green+src[RIDX(i-1, j, dim)].green+src[RIDX(i-1, j+1, dim)].green+src[RIDX(i, j+1, dim)].green+src[RIDX(i, j, dim)].green+src[RIDX(i, j-1, dim)].green+src[RIDX(i+1, j-1, dim)].green+src[RIDX(i+1, j, dim)].green+src[RIDX(i+1, j+1, dim)].green)/9;
            dst[RIDX(i, j, dim)].blue = (src[RIDX(i-1, j-1, dim)].blue+src[RIDX(i-1, j, dim)].blue+src[RIDX(i-1, j+1, dim)].blue+src[RIDX(i, j+1, dim)].blue+src[RIDX(i, j, dim)].blue+src[RIDX(i, j-1, dim)].blue+src[RIDX(i+1, j-1, dim)].blue+src[RIDX(i+1, j, dim)].blue+src[RIDX(i+1, j+1, dim)].blue)/9;
        }
    }
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    //add_smooth_function(&naive_smooth, naive_smooth_descr);
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&smooth1, smooth_descr1);
    add_smooth_function(&smooth2, smooth_descr2);
    /* ... Register additional test functions here */
}

