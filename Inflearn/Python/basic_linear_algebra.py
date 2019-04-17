# https://www.inflearn.com/course/python-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%9E%85%EB%AC%B8-%EA%B0%95%EC%A2%8C/
# code Assignmet: basic_linear_algebra

def vector_size_check(*vector_variables):

    check_set = set([])

    for i in vector_variables:
        check_set.add(len(i))

    if len(check_set) == 1 :
        result = True
    else :
        result = False

    return result


def vector_addition(*vector_variables):

    return [sum(i) for i in zip(*vector_variables)]


def vector_subtraction(*vector_variables):
    if not vector_size_check(*vector_variables):
        raise ArithmeticError

    result = []
    for i in zip(*vector_variables):
        for j in enumerate(i):
            if j[0] == 0 :
                result.append(j[1])
            else:




    return


def scalar_vector_product(alpha, vector_variable):
    return None


def matrix_size_check(*matrix_variables):
    return None


def is_matrix_equal(*matrix_variables):
    return None


def matrix_addition(*matrix_variables):
    if not matrix_size_check(*matrix_variables):
        raise ArithmeticError
    return None


def matrix_subtraction(*matrix_variables):
    if not matrix_size_check(*matrix_variables):
        raise ArithmeticError
    return None


def matrix_transpose(matrix_variable):
    return None


def scalar_matrix_product(alpha, matrix_variable):
    return None


def is_product_availability_matrix(matrix_a, matrix_b):
    return None


def matrix_product(matrix_a, matrix_b):
    if not is_product_availability_matrix(matrix_a, matrix_b):
        raise ArithmeticError
    return None

if __name__ == "__main__":
    print(vector_subtraction([1,3],[2,4],[6,7]))
