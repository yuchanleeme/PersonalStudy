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
    print(vector_variables,"123123213231")
    for i in zip(*vector_variables):
        for j in range(len(i)):
            if j == 0 :
                temp = i[j]
            else:
                temp = temp - i[j]
        result.append(temp)

    return result


def scalar_vector_product(alpha, vector_variable):

    return [alpha * i for i in vector_variable]


def matrix_size_check(*matrix_variables):

    check_set = set([])

    for i in matrix_variables:
        check_set.add(len(i))

    if len(check_set) == 1 :
        result = True
    else :
        result = False

    return result


def is_matrix_equal(*matrix_variables):

    result = True

    temp = [[len(set(j))for j in zip(*i)] for i in zip(*matrix_variables)]
    for data_1 in zip(*temp):
        for data_2 in data_1:
            if (data_2) != 1:
                result = False

    return result


def matrix_addition(*matrix_variables):
    if not matrix_size_check(*matrix_variables):
        raise ArithmeticError

    return [[sum(j) for j in zip(*i)] for i in zip(*matrix_variables)]


def matrix_subtraction(*matrix_variables):
    if not matrix_size_check(*matrix_variables):
        raise ArithmeticError

    return  [[2 * j[0] - sum(j) for j in zip(*i)] for i in zip(*matrix_variables)]


def matrix_transpose(matrix_variable):

    return [list(data) for data in zip(*matrix_variable)]


def scalar_matrix_product(alpha, matrix_variable):

    return [[alpha * j for j in i] for i in matrix_variable]


def is_product_availability_matrix(matrix_a, matrix_b):

    return len(matrix_transpose(matrix_a)) == len(matrix_b)


def matrix_product(matrix_a, matrix_b):
    if not is_product_availability_matrix(matrix_a, matrix_b):
        raise ArithmeticError

    return [[sum(a*b for a,b in zip(row_a,row_b)) for row_b in matrix_transpose(matrix_b)] for row_a in matrix_a]
