/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab P03 weekday
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


/// @brief point of two coordinate axes
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct {
	double x;
	double y;
} point_t;


// END-STUDENTS-TO-ADD-CODE

/// @brief box with an origin point and a dimension w and h
// BEGIN-STUDENTS-TO-ADD-CODE
typedef struct{
	point_t p;
	double w;
	double h;
} box_t;


// END-STUDENTS-TO-ADD-CODE

/// @brief triangle given by three points a, b, and c
// BEGIN-STUDENTS-TO-ADD-CODE

typedef struct {
	point_t a;
	point_t b;
	point_t c;
} triangle_t;

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   Compares two double values with a given hard coded tolerance.
 * @param   [in] a  the first value
 * @param   [in] b  the second value
 * @returns 0 if fabs(a-b) <= tolerance, -1 if a < b, 1 otherwise
 * @remark  the tolerance is expected to be 0.05 (internally hard coded)
 */
// BEGIN-STUDENTS-TO-ADD-CODE

static int compare_double(double a, double b){
	double tolerance = 0.05;
	if (fabs(a-b) <= tolerance){
		return 0;
	} else if (a < b){
		return -1;
	}
	return 1;
}


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   Compares two box parameters for their area (w * h of the box).
 * @param   [in] a  the first box
 * @param   [in] b  the second box
 * @returns the return value from compare_double() when given the areas of both boxes as parameter to compare_double()
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int compare_area(box_t a, box_t b){
	double area_a = a.h * a.w;
	double area_b = b.h * b.w;

	return compare_double(area_a, area_b);
}


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   Compares the area of the parameter against 0.
 * @param   [in] box   the box to check against area 0
 * @returns compare_double() == 0 with the boxes area and 0 as parameters
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_zero_area(box_t box){
	double area_box = box.h * box.w;
	return (compare_double(area_box, 0.0) == 0);
}


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   Calculates the bounding box of a triangle
 * @param   [in] t   the trinagle for which the baounding box is to be calculated
 * @returns the bounding box of the triangle
 * @remark  calculates first the point with the minimum x and y of the triangle's points,
 *          plus as second point the one with the max coordinates of all points
 * @remark  the minial point is the origin of the bounding box, the width and hight is the x/y delta of the two points
 *
 */
// BEGIN-STUDENTS-TO-ADD-CODE
box_t triangle_bounding_box(triangle_t t){
	box_t box;
	point_t point;

	double min_x = fmin(t.a.x, fmin(t.b.x, t.c.x));
	double min_y = fmin(t.a.y, fmin(t.b.y, t.c.y));

	double max_x = fmax(t.a.x, fmax(t.b.x, t.c.x));
	double max_y = fmax(t.a.y, fmax(t.b.y, t.c.y));

	point.x = min_x;
	point.y = min_y;
	box.p = point;
	box.h = max_y - min_y;
	box.w = max_x - min_x;

	return box;
}


// END-STUDENTS-TO-ADD-CODE


// forward declaration of used functions in main()
static box_t get_match(box_t board, triangle_t t);
static triangle_t triangle_rotate(triangle_t t, double degree);
static void write_data(box_t board, triangle_t t, int degree);


/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[])
{
    int x1, x2, x3, y1, y2, y3;
    if (argc < 2 || sscanf(argv[1], "%d/%d-%d/%d-%d/%d", &x1, &y1, &x2, &y2, &x3, &y3) != 6) {
        fprintf(stderr, "Usage: %s x1/y1-x2/y2-x3/y3\ne.g. 0/0-100/0-50/50\n", argv[0]);
        return EXIT_FAILURE;
        
    }

    box_t board = { { 0, 0 }, 100, 200 };
    
    // rotate the triangle in steps of 1 degree to find the "best position" of the triangle in the board
    triangle_t t = { { x1, y1 }, { x2, y2 }, { x3, y3 } };
    int degree_best = -1;
    box_t best;
    for(int degree = 0; degree < 360; degree++) {
        box_t match = get_match(board, triangle_rotate(t, degree));
        if (!is_zero_area(match)) {
            if (degree_best == -1 || compare_area(match, best) < 0) {
                degree_best = degree;
                best = match;
            }
        }
    }

    // write as tabular file
    write_data(board, t, degree_best);
    
    return EXIT_SUCCESS;
}


/****************** internal functions ********************/

// forward declarations
static point_t point_rotate(point_t p, double degree);
static point_t point_move(point_t p, double dx, double dy);
static triangle_t triangle_move(triangle_t t, double dx, double dy);


static box_t get_match(box_t board, triangle_t t)
{
    box_t b = triangle_bounding_box(t);
    if (compare_double(board.w, b.w) < 0) return (box_t){ board.p, 0, 0 };
    if (compare_double(board.h, b.h) < 0) return (box_t){ board.p, 0, 0 };
    return (box_t){ board.p, b.w, b.h };
}

static triangle_t triangle_rotate(triangle_t t, double degree)
{
    return (triangle_t){ point_rotate(t.a, degree), point_rotate(t.b, degree), point_rotate(t.c, degree)  };
}

static triangle_t triangle_move(triangle_t t, double dx, double dy)
{
    return (triangle_t){ point_move(t.a, dx, dy), point_move(t.b, dx, dy), point_move(t.c, dx, dy)  };
}

static point_t point_rotate(point_t p, double degree)
{
    double rad = fmod(degree, 360.0) * acos(-1.0) / 180.0;
    double s = sin(rad);
    double c = cos(rad);
    
    return (point_t){ c*p.x - s*p.y, s*p.x + c*p.y };
}

static point_t point_move(point_t p, double dx, double dy)
{
    return (point_t) { p.x+dx, p.y+dy };
}

static void write_data(box_t board, triangle_t t, int degree)
{
    double border = 10.0;
    double gap = 2*border;

    // move board to origin
    board.p.x = 0.0;
    board.p.y = 0.0;

    // move original triangle to above the board
    box_t tbb = triangle_bounding_box(t);
    t = triangle_move(t, -tbb.p.x, -tbb.p.y + board.h + gap);
    tbb.p.x = 0.0;
    tbb.p.y = board.h + gap;

    // view box
    box_t view = { { -border, -border }, fmax(board.w, tbb.w) + 2 * border, board.h + gap + tbb.h + 2 * border };
    printf("viewbox:%.1f:%.1f:%.1f:%.1f\n", view.p.x, view.p.y, view.w, view.h);
    
    printf("rect:%.1f:%.1f:%.1f:%.1f:%s\n", board.p.x, board.p.y, board.w, board.h, "gray");
    printf("polygon:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%s\n",  t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y, "green");

    // there was a match, show it
    if (degree >= 0) {
        triangle_t rotated = triangle_rotate(t, degree);
        box_t rbb = triangle_bounding_box(rotated);
        t = triangle_move(rotated, -rbb.p.x, -rbb.p.y); // move to origin
        printf("polygon:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%s\n",  t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y, "yellow");
    }
}
