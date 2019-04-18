# https://www.inflearn.com/course/python-%ED%8C%8C%EC%9D%B4%EC%8D%AC-%EC%9E%85%EB%AC%B8-%EA%B0%95%EC%A2%8C/
# code Assignmet: basic_linear_algebra

def vector_size_check(*vector_variables):

    return len(set([len(value) for value in vector_variables])) == 1


def vector_addition(*vector_variables):

    return [sum(i) for i in zip(*vector_variables)]


def vector_subtraction(*vector_variables):
    if not vector_size_check(*vector_variables):
        raise ArithmeticError

    return [2*row[0]-sum(row) for row in zip(*vector_variables)]


def scalar_vector_product(alpha, vector_variable):

    return [alpha * i for i in vector_variable]


def matrix_size_check(*matrix_variables):

    return len(set([len(matrix) for matrix in matrix_variables])) == 1


def is_matrix_equal(*matrix_variables):

    # <크기가 같지 않아도 정상 판단 가능>
    # result = True
    #
    # temp = [[len(set(j))for j in zip(*i)] for i in zip(*matrix_variables)]
    # for data_1 in zip(*temp):
    #     for data_2 in data_1:
    #         if (data_2) != 1:
    #             result = False
    # return result

    return set([len(set([len(set(col)) for col in zip(*row)])) for row in zip(*matrix_variables)]) == {1}
    # matrix의 크기가 같다는 가정하에는 pythonic code 작성 가능
    # 그 이외에 사항은 좀 더 공부 후에 수정예정


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
