struct complex
{
    double real;
    double imag;
};

struct complex add(struct complex a, struct complex b) 
{
    struct complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

struct complex subtract(struct complex a, struct complex b) 
{
    struct complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

struct complex multiply(struct complex a, struct complex b)
 {
    struct complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}
int choice;
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int i, j, k; // for loops
    int mains, op, choice, rows1, cols1, rows2, cols2, shapeChoice, eqType, num, n, root, logType, logOp, trigChoice;
    int matrix1[10][10], matrix2[10][10], result[10][10];
    double a, b, c, sum, mean, variance, stddev, base, exponent, power, number, angleDeg, angleRad, resultD, area, perimeter, root1, root2, discriminant, realPart, imagPart, log1, log2;
    double data[100];
    long long factorial;
    struct complex x, y, res;
    do
    {
        int mains;
        printf("\n");
        printf("\n");
        printf("************ ENTER YOUR CHOICE ************\n");
        printf("\n");
        printf("       1.  Arithmetic operations\n");
        printf("\n");
        printf("       2.  Complex operations\n");
        printf("\n");
        printf("       3.  Matrix operations\n");
        printf("\n");
        printf("       4.  Logarithmic operation\n");
        printf("\n");
        printf("       5.  Exponential operator\n");
        printf("\n");
        printf("       6.  Trignometric operations\n");
        printf("\n");
        printf("       7.  Equational operations\n");
        printf("\n");
        printf("       8.  Power operator\n");
        printf("\n");
        printf("       9.  Root operator\n");
        printf("\n");
        printf("       10. Statistical operation\n");
        printf("\n");
        printf("       11. Areas\n");
        printf("\n");
        printf("       12. Factorial operator\n");
        printf("\n");
        printf("       0.  exit\n");
        printf("\n");     
        printf("************ ENTER YOUR CHOICE ************\n\n\t\t    ");
        
        scanf("%d",&mains);
        printf("\n");
        switch (mains)
        {
            case 0:
            {
                exit(0);
            }
            break;
            case 1:{
                // Arithmetic operations
                int op;
                double a, b;
                printf("\n==========================================================\n");
                printf("                    Arithmetic Operations                   \n");
                printf("==========================================================\n");
                printf("    1. Addition\n");
                printf("    2. Subtraction\n");
                printf("    3. Multiplication\n");
                printf("    4. Division\n");
                printf("    5. Remainder (Modulus)\n");
                printf("----------------------------------------------------------\n");
                printf("Enter your choice (1-5): ");
                scanf("%d", &op);

                if (op >= 1 && op <= 5) {
                    printf("\nEnter first number : "); scanf("%lf", &a);
                    printf("Enter second number: "); scanf("%lf", &b);

                    printf("\n----------------------------------------------------------\n");
                    switch (op) {
                        case 1:
                            printf("Result: %.2lf + %.2lf = %.2lf\n", a, b, a + b);
                            break;
                        case 2:
                            printf("Result: %.2lf - %.2lf = %.2lf\n", a, b, a - b);
                            break;
                        case 3:
                            printf("Result: %.2lf * %.2lf = %.2lf\n", a, b, a * b);
                            break;
                        case 4:
                            if (b == 0) {
                                printf("Error: Division by zero is undefined.\n");
                            } else {
                                printf("Result: %.2lf / %.2lf = %.2lf\n", a, b, a / b);
                            }
                            break;
                        case 5:
                            if ((int)b == 0) {
                                printf("Error: Modulus by zero is undefined.\n");
                            } else {
                                printf("Result: %d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
                            }
                            break;
                    }
                    printf("----------------------------------------------------------\n");
                } else {
                    printf("\nInvalid choice. Please select a valid arithmetic operation.\n");
                }
                break;
            }
            case 2: { 
                // Complex operations
                struct complex x, y, res;
                int op;

                printf("\n==========================================================\n");
                printf("                    Complex Number Operations               \n");
                printf("==========================================================\n");
                printf("    1. Addition\n");
                printf("    2. Subtraction\n");
                printf("    3. Multiplication\n");
                printf("----------------------------------------------------------\n");
                printf("Enter your choice (1-3): ");
                scanf("%d", &op);

                if (op >= 1 && op <= 3) {
                    printf("\nEnter real part of first complex number   : "); scanf("%lf", &x.real);
                    printf("Enter imaginary part of first complex number: "); scanf("%lf", &x.imag);
                    printf("\nEnter real part of second complex number  : "); scanf("%lf", &y.real);
                    printf("Enter imaginary part of second complex number: "); scanf("%lf", &y.imag);

                    printf("\n----------------------------------------------------------\n");
                    switch (op) {
                        case 1:
                            res = add(x, y);
                            printf("Result: (%.2lf + %.2lfi) + (%.2lf + %.2lfi) = %.2lf + %.2lfi\n",
                                   x.real, x.imag, y.real, y.imag, res.real, res.imag);
                            break;
                        case 2:
                            res = subtract(x, y);
                            printf("Result: (%.2lf + %.2lfi) - (%.2lf + %.2lfi) = %.2lf + %.2lfi\n",
                                   x.real, x.imag, y.real, y.imag, res.real, res.imag);
                            break;
                        case 3:
                            res = multiply(x, y);
                            printf("Result: (%.2lf + %.2lfi) * (%.2lf + %.2lfi) = %.2lf + %.2lfi\n",
                                   x.real, x.imag, y.real, y.imag, res.real, res.imag);
                            break;
                    }
                    printf("----------------------------------------------------------\n");
                } else {
                    printf("\nInvalid choice. Please select a valid complex operation.\n");
                }

                break;
            }
            case 3: { // Matrix operations
                int rows1, cols1, rows2, cols2, choice;
                int matrix1[10][10], matrix2[10][10], result[10][10];

                printf("==========================================================");
                printf("                        Matrix Operations                   ");
                printf("==========================================================");
                printf("    1. Addition");
                printf("    2. Subtraction");
                printf("    3. Multiplication");
                printf("----------------------------------------------------------");
                printf("Enter your choice (1-3): ");
                scanf("%d", &choice);

                if (choice >= 1 && choice <= 3) {
                    printf("Enter number of rows for Matrix 1: ");
                    scanf("%d", &rows1);
                    printf("Enter number of columns for Matrix 1: ");
                    scanf("%d", &cols1);

                    if (choice == 3) {
                        printf("Enter number of rows for Matrix 2: ");
                        scanf("%d", &rows2);
                        printf("Enter number of columns for Matrix 2: ");
                        scanf("%d", &cols2);

                        if (cols1 != rows2) {
                            printf("Error: Cannot multiply matrices with dimensions %dx%d and %dx%d.",rows1, cols1, rows2, cols2);
                            break;
                        }
                    } else {
                        rows2 = rows1;
                        cols2 = cols1;
                    }

                    printf("Enter elements for Matrix 1:");
                    for (i = 0; i < rows1; i++) {
                        for (j = 0; j < cols1; j++) {
                            printf("Matrix1[%d][%d] = ", i, j);
                            scanf("%d", &matrix1[i][j]);
                        }
                    }

                    printf("Enter elements for Matrix 2:");
                    for (i = 0; i < rows2; i++) {
                        for (j = 0; j < cols2; j++) {
                            printf("Matrix2[%d][%d] = ", i, j);
                            scanf("%d", &matrix2[i][j]);
                        }
                    }

                    printf("----------------------------------------------------------");

                    if (choice == 1 || choice == 2) {
                        if (rows1 != rows2 || cols1 != cols2) {
                            printf("Error: Matrix dimensions must match for addition or subtraction");
                        } else {
                            for (i = 0; i < rows1; i++) {
                                for (j = 0; j < cols1; j++) {
                                    result[i][j] = (choice == 1)
                                                   ? matrix1[i][j] + matrix2[i][j]
                                                   : matrix1[i][j] - matrix2[i][j];
                                }
                            }
                            printf("Resultant Matrix:");
                            for (i = 0; i < rows1; i++) {
                                for (j = 0; j < cols1; j++) {
                                    printf("%6d ", result[i][j]);
                                }
                                printf("\n");
                            }
                        }
                    } else if (choice == 3) {
                        for (i = 0; i < rows1; i++) {
                            for (j = 0; j < cols2; j++) {
                                result[i][j] = 0;
                                for ( k = 0; k < cols1; k++) {
                                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                                }
                            }
                        }
                        printf("Resultant Matrix (Multiplication):");
                        for (i = 0; i < rows1; i++) {
                            for (j = 0; j < cols2; j++) {
                                printf("%6d ", result[i][j]);
                            }
                            printf("\n");
                        }
                    }

                    printf("----------------------------------------------------------");
                } else {
                    printf("Invalid choice. Please select a valid matrix operation.");
                }

                break;
            }
            case 4: { // Logarithmic operations
                int logType, logOp;
                double num1, num2, base, log1, log2, result;

                printf("\n==========================================================\n");
                printf("                    Logarithmic Operations                  \n");
                printf("==========================================================\n");
                printf("    1. Natural Logarithm (ln)\n");
                printf("    2. Custom Base Logarithm\n");
                printf("    3. Arithmetic on Logs (log(x) op log(y))\n");
                printf("----------------------------------------------------------\n");
                printf("Enter your choice (1-3): ");
                scanf("%d", &logType);

                switch (logType) {
                    case 1:
                        printf("\nEnter number (> 0): ");
                        scanf("%lf", &num1);
                        if (num1 <= 0) {
                            printf("Error: Logarithm undefined for zero or negative values.\n");
                        } else {
                            printf("\nResult: ln(%.4lf) = %.4lf\n", num1, log(num1));
                        }
                        break;

                    case 2:
                        printf("\nEnter number (> 0): ");
                        scanf("%lf", &num1);
                        printf("Enter base (> 0 and != 1): ");
                        scanf("%lf", &base);
                        if (num1 <= 0 || base <= 0 || base == 1) {
                            printf("Error: Invalid input. Base must be > 0 and != 1, number must be > 0.\n");
                        } else {
                            result = log(num1) / log(base);
                            printf("\nResult: log_base%.2lf(%.2lf) = %.4lf\n", base, num1, result);
                        }
                        break;

                    case 3:
                        printf("\nAvailable Operations on Logs:\n");
                        printf("    1. log(x) + log(y)\n");
                        printf("    2. log(x) - log(y)\n");
                        printf("    3. log(x) * log(y)\n");
                        printf("    4. log(x) / log(y)\n");
                        printf("----------------------------------------------------------\n");
                        printf("Enter your choice (1-4): ");
                        scanf("%d", &logOp);

                        printf("\nEnter number x (> 0): ");
                        scanf("%lf", &num1);
                        printf("Enter number y (> 0): ");
                        scanf("%lf", &num2);
                        printf("Enter base (> 0 and != 1): ");
                        scanf("%lf", &base);

                        if (num1 <= 0 || num2 <= 0 || base <= 0 || base == 1) {
                            printf("Error: Invalid input values.\n");
                            break;
                        }

                        log1 = log(num1) / log(base);
                        log2 = log(num2) / log(base);

                        printf("\n----------------------------------------------------------\n");
                        switch (logOp) {
                            case 1:
                                result = log1 + log2;
                                printf("log%.0lf(%.2lf) + log%.0lf(%.2lf) = %.4lf\n", base, num1, base, num2, result);
                                break;
                            case 2:
                                result = log1 - log2;
                                printf("log%.0lf(%.2lf) - log%.0lf(%.2lf) = %.4lf\n", base, num1, base, num2, result);
                                break;
                            case 3:
                                result = log1 * log2;
                                printf("log%.0lf(%.2lf) * log%.0lf(%.2lf) = %.4lf\n", base, num1, base, num2, result);
                                break;
                            case 4:
                                if (log2 == 0)
                                    printf("Error: Division by zero (log(y) = 0).\n");
                                else {
                                    result = log1 / log2;
                                    printf("log%.0lf(%.2lf) / log%.0lf(%.2lf) = %.4lf\n", base, num1, base, num2, result);
                                }
                                break;
                            default:
                                printf("Invalid operation choice.\n");
                        }
                        printf("----------------------------------------------------------\n");
                        break;

                    default:
                        printf("Invalid log operation selected.\n");
                }

                break;
            }

            case 5: {
                double power, result;
                
                printf("\n==========================================================\n");
                printf("                    Exponential Operation                  \n");
                printf("==========================================================\n");
                printf("This operation calculates the exponential value e^x.\n");
                printf("----------------------------------------------------------\n");
                printf("Enter the exponent value (x): ");
                scanf("%lf", &power);
                
                result = exp(power);
                
                printf("\nResult: e^%.4lf = %.6lf\n", power, result);
                printf("----------------------------------------------------------\n");
                break;
            }

            case 6: { // Trigonometric operations
                int trigChoice;
                double angleDeg, angleRad, result;

                printf("\n==========================================================\n");
                printf("                   Trigonometric Operations                \n");
                printf("==========================================================\n");
                printf("    1. sin(x)\n");
                printf("    2. cos(x)\n");
                printf("    3. tan(x)\n");
                printf("    4. cot(x)\n");
                printf("    5. sec(x)\n");
                printf("    6. csc(x)\n");
                printf("----------------------------------------------------------\n");
                printf("Enter your choice (1-6): ");
                scanf("%d", &trigChoice);

                printf("\nEnter angle in degrees: ");
                scanf("%lf", &angleDeg);

                angleRad = angleDeg * (M_PI / 180.0);

                printf("\n----------------------------------------------------------\n");
                switch (trigChoice) {
                    case 1:
                        result = sin(angleRad);
                        printf("Result: sin(%.2lf�) = %.6lf\n", angleDeg, result);
                        break;
                    case 2:
                        result = cos(angleRad);
                        printf("Result: cos(%.2lf�) = %.6lf\n", angleDeg, result);
                        break;
                    case 3:
                        if (fmod(fabs(angleDeg), 180.0) == 90.0)
                            printf("Result: tan(%.2lf�) is undefined.\n", angleDeg);
                        else {
                            result = tan(angleRad);
                            printf("Result: tan(%.2lf�) = %.6lf\n", angleDeg, result);
                        }
                        break;
                    case 4:
                        if (fmod(angleDeg, 180.0) == 0.0)
                            printf("Result: cot(%.2lf�) is undefined.\n", angleDeg);
                        else {
                            result = 1.0 / tan(angleRad);
                            printf("Result: cot(%.2lf�) = %.6lf\n", angleDeg, result);
                        }
                        break;
                    case 5:
                        if (fmod(fabs(angleDeg), 180.0) == 90.0)
                            printf("Result: sec(%.2lf�) is undefined.\n", angleDeg);
                        else {
                            result = 1.0 / cos(angleRad);
                            printf("Result: sec(%.2lf�) = %.6lf\n", angleDeg, result);
                        }
                        break;
                    case 6:
                        if (fmod(angleDeg, 180.0) == 0.0)
                            printf("Result: csc(%.2lf�) is undefined.\n", angleDeg);
                        else {
                            result = 1.0 / sin(angleRad);
                            printf("Result: csc(%.2lf�) = %.6lf\n", angleDeg, result);
                        }
                        break;
                    default:
                        printf("Invalid trigonometric operation selected.\n");
                }
                printf("----------------------------------------------------------\n");
                break;
            }

            case 7: { // Equation solving
                int eqType;
                double a, b, c, root1, root2, discriminant;

                printf("\n==========================================================\n");
                printf("                       Equation Solver                     \n");
                printf("==========================================================\n");
                printf("    1. Linear Equation (ax + b = 0)\n");
                printf("    2. Quadratic Equation (ax^2 + bx + c = 0)\n");
                printf("----------------------------------------------------------\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &eqType);

                switch (eqType) {
                    case 1:
                        printf("\nSolving equation of the form ax + b = 0\n");
                        printf("Enter coefficient a: ");
                        scanf("%lf", &a);
                        printf("Enter constant b   : ");
                        scanf("%lf", &b);
                        if (a == 0) {
                            if (b == 0)
                                printf("Result: Infinite solutions (0 = 0)\n");
                            else
                                printf("Result: No solution (inconsistent equation)\n");
                        } else {
                            printf("Result: x = %.4lf\n", -b / a);
                        }
                        break;

                    case 2:
                        printf("\nSolving equation of the form ax^2 + bx + c = 0\n");
                        printf("Enter coefficient a: ");
                        scanf("%lf", &a);
                        printf("Enter coefficient b: ");
                        scanf("%lf", &b);
                        printf("Enter constant c   : ");
                        scanf("%lf", &c);

                        if (a == 0) {
                            printf("This is not a quadratic equation. Try linear equation.\n");
                        } else {
                            discriminant = b * b - 4 * a * c;
                            printf("\nDiscriminant (b^2 - 4ac) = %.4lf\n", discriminant);

                            if (discriminant > 0) {
                                root1 = (-b + sqrt(discriminant)) / (2 * a);
                                root2 = (-b - sqrt(discriminant)) / (2 * a);
                                printf("Two real and distinct roots:\n");
                                printf("x1 = %.4lf\n", root1);
                                printf("x2 = %.4lf\n", root2);
                            } else if (discriminant == 0) {
                                root1 = -b / (2 * a);
                                printf("One real and repeated root:\n");
                                printf("x = %.4lf\n", root1);
                            } else {
                                double realPart = -b / (2 * a);
                                double imagPart = sqrt(-discriminant) / (2 * a);
                                printf("Two complex roots:\n");
                                printf("x1 = %.4lf + %.4lfi\n", realPart, imagPart);
                                printf("x2 = %.4lf - %.4lfi\n", realPart, imagPart);
                            }
                        }
                        break;

                    default:
                        printf("Invalid equation type selected.\n");
                }

                printf("----------------------------------------------------------\n");
                break;
            }

            case 8: { // Power operator
                double base, exponent, result;

                printf("\n==========================================================\n");
                printf("                         Power Operation                   \n");
                printf("==========================================================\n");
                printf("This operation calculates base raised to the power exponent.\n");
                printf("----------------------------------------------------------\n");

                printf("Enter base value    : ");
                scanf("%lf", &base);
                printf("Enter exponent value: ");
                scanf("%lf", &exponent);

                if (base == 0 && exponent <= 0) {
                    printf("\nError: 0 raised to 0 or negative exponent is undefined.\n");
                } else {
                    result = pow(base, exponent);
                    printf("\nResult: %.4lf ^ %.4lf = %.6lf\n", base, exponent, result);
                }

                printf("----------------------------------------------------------\n");
                break;
            }

            case 9: { // Root operator
                double number;
                int root;
                double result;

                printf("\n==========================================================\n");
                printf("                         Root Operation                    \n");
                printf("==========================================================\n");
                printf("This operation calculates the nth root of a number.\n");
                printf("----------------------------------------------------------\n");

                printf("Enter the number        : ");
                scanf("%lf", &number);
                printf("Enter the root value (n): ");
                scanf("%d", &root);

                if (root == 0) {
                    printf("\nError: Zeroth root is undefined.\n");
                } else if (number < 0 && root % 2 == 0) {
                    printf("\nError: Even root of a negative number is not real.\n");
                } else {
                    result = pow(number, 1.0 / root);
                    printf("\nResult: %.2lf-th root of %.2lf = %.6lf\n", (double)root, number, result);
                }

                printf("----------------------------------------------------------\n");
                break;
            }

            case 10: { // Statistical operation
                int n;
                double data[100], sum = 0, mean = 0, variance = 0, stddev = 0;

                printf("\n==========================================================\n");
                printf("                    Statistical Operation                  \n");
                printf("==========================================================\n");
                printf("This operation calculates mean, variance, and standard deviation.\n");
                printf("----------------------------------------------------------\n");

                printf("Enter number of elements (max 100): ");
                scanf("%d", &n);

                if (n <= 0 || n > 100) {
                    printf("\nError: Invalid number of elements. Must be between 1 and 100.\n");
                    break;
                }

                printf("\nEnter %d elements:\n", n);
                for (i = 0; i < n; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%lf", &data[i]);
                    sum += data[i];
                }

                mean = sum / n;

                for (i = 0; i < n; i++) {
                    variance += pow(data[i] - mean, 2);
                }

                variance /= n;
                stddev = sqrt(variance);

                printf("\n----------------------------------------------------------\n");
                printf("Mean              = %.4lf\n", mean);
                printf("Variance          = %.4lf\n", variance);
                printf("Standard Deviation= %.4lf\n", stddev);
                printf("----------------------------------------------------------\n");
                break;
            }

            case 11: { // Area and Perimeter
                int shapeChoice;
                double area = 0, perimeter = 0;
                printf("\n==========================================================\n");
                printf("                    Area and Perimeter Calculator          \n");
                printf("==========================================================\n");
                printf("    1. Circle\n");
                printf("    2. Rectangle\n");
                printf("    3. Square\n");
                printf("    4. Triangle (Equilateral)\n");
                printf("----------------------------------------------------------\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &shapeChoice);

                switch (shapeChoice) {
                    case 1: { // Circle
                        double radius;
                        printf("\nEnter radius: ");
                        scanf("%lf", &radius);
                        if (radius < 0) {
                            printf("\nError: Radius cannot be negative.\n");
                        } else {
                            area = M_PI * radius * radius;
                            perimeter = 2 * M_PI * radius;
                            printf("\nArea      = %.4lf\n", area);
                            printf("Circumference = %.4lf\n", perimeter);
                        }
                        break;
                    }
                    case 2: { // Rectangle
                        double length, width;
                        printf("\nEnter length: ");
                        scanf("%lf", &length);
                        printf("Enter width : ");
                        scanf("%lf", &width);
                        if (length < 0 || width < 0) {
                            printf("\nError: Length and width must be non-negative.\n");
                        } else {
                            area = length * width;
                            perimeter = 2 * (length + width);
                            printf("\nArea      = %.4lf\n", area);
                            printf("Perimeter = %.4lf\n", perimeter);
                        }
                        break;
                    }
                    case 3: { // Square
                        double side;
                        printf("\nEnter side length: ");
                        scanf("%lf", &side);
                        if (side < 0) {
                            printf("\nError: Side length must be non-negative.\n");
                        } else {
                            area = side * side;
                            perimeter = 4 * side;
                            printf("\nArea      = %.4lf\n", area);
                            printf("Perimeter = %.4lf\n", perimeter);
                        }
                        break;
                    }
                    case 4: { // Triangle (Equilateral)
                        double side;
                        printf("\nEnter side length: ");
                        scanf("%lf", &side);
                        if (side < 0) {
                            printf("\nError: Side length must be non-negative.\n");
                        } else {
                            area = (sqrt(3) / 4) * side * side;
                            perimeter = 3 * side;
                            printf("\nArea      = %.4lf\n", area);
                            printf("Perimeter = %.4lf\n", perimeter);
                        }
                        break;
                    }
                    default:
                        printf("\nInvalid shape selected.\n");
                }

                printf("----------------------------------------------------------\n");
                break;
            }

            case 12: { // Factorial operator
                int num;
                long long factorial = 1;

                system("cls");
                printf("\n==========================================================\n");
                printf("                        Factorial Operation                \n");
                printf("==========================================================\n");
                printf("This operation calculates the factorial of a non-negative integer.\n");
                printf("----------------------------------------------------------\n");

                printf("Enter an integer: ");
                scanf("%d", &num);

                if (num < 0) {
                    printf("\nError: Factorial is undefined for negative numbers.\n");
                } else {
                    for (i = 1; i <= num; i++) {
                        factorial *= i;
                    }
                    printf("\nResult: %d! = %lld\n", num, factorial);
                }

                printf("----------------------------------------------------------\n");
                break;
            }
            
            default:
                printf("\nInvalid choice. Please enter a number between 0 and 12.\n");
        }
        printf("\n\n\n************ ENTER YOUR CHOICE ************\n\n\t\t    ");
        
        printf("1.continue\n\t\t    ");
        
        printf("2.stop\n\n\t\t\t");
        scanf("%d",&choice);
    }
    while(choice==1);

    return 0;
}
