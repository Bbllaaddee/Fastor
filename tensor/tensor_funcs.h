#ifndef TENSOR_FUNCS_H
#define TENSOR_FUNCS_H

#include "tensor/Tensor.h"

namespace Fastor {

template<typename T, size_t I, size_t J>
FASTOR_INLINE Tensor<T,J,I> transpose(const Tensor<T,I,J> &a) {
    Tensor<T,J,I> out;
    _transpose<T,I,J>(static_cast<const T *>(a.data()),out.data());
    return out;
}

template<typename T, size_t I>
FASTOR_INLINE T trace(const Tensor<T,I,I> &a) {
    return _trace<T,I,I>(static_cast<const T *>(a.data()));
}

template<typename T, size_t I>
FASTOR_INLINE T determinant(const Tensor<T,I,I> &a) {
    return _det<T,I,I>(static_cast<const T *>(a.data()));
}

template<typename T, size_t I>
FASTOR_INLINE Tensor<T,I,I> cofactor(const Tensor<T,I,I> &a) {
    Tensor<T,I,I> out;
    _cofactor<T,I,I>(a.data(),out.data());
    return out;
}

template<typename T, size_t I>
FASTOR_INLINE Tensor<T,I,I> adjoint(const Tensor<T,I,I> &a) {
    Tensor<T,I,I> out;
    _adjoint<T,I,I>(a.data(),out.data());
    return out;
}

template<typename T, size_t I>
FASTOR_INLINE Tensor<T,I,I> inverse(const Tensor<T,I,I> &a) {
    return adjoint(a)/determinant(a);
}

template<typename T, size_t ... Rest>
FASTOR_INLINE T norm(const Tensor<T,Rest...> &a) {
    if (sizeof...(Rest) == 0)
        return *a.data();
    return _norm<T,prod<Rest...>::value>(a.data());
}

// matmul - matvec overloads
template<typename T, size_t I, size_t J, size_t K>
FASTOR_INLINE Tensor<T,I,K> matmul(const Tensor<T,I,J> &a, const Tensor<T,J,K> &b) {
    Tensor<T,I,K> out; out.zeros();
    _matmul<T,I,J,K>(a.data(),b.data(),out.data());
    return out;
}

template<typename T, size_t I, size_t J>
FASTOR_INLINE Tensor<T,J> matmul(const Tensor<T,I,J> &a, const Tensor<T,J> &b) {
    Tensor<T,J> out;
    _matmul<T,I,J,1>(a.data(),b.data(),out.data());
    return out;
}

template<typename T, size_t I, size_t J>
FASTOR_INLINE Tensor<T,I> matmul(const Tensor<T,J> &b, const Tensor<T,J,I> &a) {
    Tensor<T,I> out;
    _matmul<T,J,I,1>(a.data(),b.data(),out.data());
    return out;
}

// Tensor cross product of two 2nd order tensors
template<typename T, size_t I, size_t J, typename std::enable_if<I==3 && J==3,bool>::type=0>
FASTOR_INLINE Tensor<T,I,J> cross(const Tensor<T,I,J> &b, const Tensor<T,I,J> &a) {
    Tensor<T,I,J> out;
    _crossproduct<T,I,I,J>(a.data(),b.data(),out.data());
    return out;
}

template<typename T, size_t I, size_t J, typename std::enable_if<I==2 && J==2,bool>::type=0>
FASTOR_INLINE Tensor<T,I+1,J+1> cross(const Tensor<T,I,J> &b, const Tensor<T,I,J> &a) {
    Tensor<T,I+1,J+1> out;
    _crossproduct<T,I,I,J>(a.data(),b.data(),out.data());
    return out;
}

// Tensor cross product of a vector with 2nd order tensor
template<typename T, size_t I, size_t J, typename std::enable_if<I==3 && J==3,bool>::type=0>
FASTOR_INLINE Tensor<T,I,J> cross(const Tensor<T,I> &b, const Tensor<T,I,J> &a) {
    Tensor<T,I,J> out;
    _crossproduct<T,I,1,J>(a.data(),b.data(),out.data());
    return out;
}

template<typename T, size_t I, size_t J, typename std::enable_if<I==2 && J==2,bool>::type=0>
FASTOR_INLINE Tensor<T,I+1,J+1> cross(const Tensor<T,I> &b, const Tensor<T,I,J> &a) {
    Tensor<T,I+1,J+1> out;
    _crossproduct<T,I,1,J>(a.data(),b.data(),out.data());
    return out;
}

// Tensor cross product of a 2nd order tensor with a vector
template<typename T, size_t I, size_t J, typename std::enable_if<I==3 && J==3,bool>::type=0>
FASTOR_INLINE Tensor<T,I,J> cross(const Tensor<T,I,J> &b, const Tensor<T,J> &a) {
    Tensor<T,I,J> out;
    _crossproduct<T,I,J,1>(a.data(),b.data(),out.data());
    return out;
}

template<typename T, size_t I, size_t J, typename std::enable_if<I==2 && J==2,bool>::type=0>
FASTOR_INLINE Tensor<T,I+1,J+1> cross(const Tensor<T,I,J> &b, const Tensor<T,J> &a) {
    Tensor<T,I+1,J+1> out;
    _crossproduct<T,I,J,1>(a.data(),b.data(),out.data());
    return out;
}


// Tensor cross product of a 3rd order tensors
template<typename T, size_t I, size_t J, size_t K, size_t L, size_t M, size_t N,
         typename std::enable_if<I==3 && J==3 && K==3 && L==3 && M==3 && N==3,bool>::type=0>
FASTOR_INLINE Tensor<T,I,3,3,N> cross(const Tensor<T,I,J,K> &A, const Tensor<T,L,M,N> &B) {
    Tensor<T,I,3,3,N> C;
    _crossproduct<T,I,J,K,L,M,N>(A.data(),B.data(),C.data());
    return C;
}


// Tensor cross product of a 4th order tensors
template<typename T, size_t I, size_t J, size_t K, size_t L, size_t M, size_t N, size_t O, size_t P,
         typename std::enable_if<I==3 && J==3 && K==3 && L==3 && M==3 && N==3 && O==3 && P==3,bool>::type=0>
FASTOR_INLINE Tensor<T,I,J,3,3,O,P> cross(const Tensor<T,I,J,K,L> &A, const Tensor<T,M,N,O,P> &B) {
    Tensor<T,I,J,3,3,O,P> C;
    _crossproduct<T,I,J,K,L,M,N,O,P>(A.data(),B.data(),C.data());
    return C;
}


// Constant tensors
static FASTOR_INLINE
Tensor<float,3,3,3> levi_civita_ps() {
    Tensor<float,3,3,3> LeCi_ps;
    LeCi_ps(0,1,2) = 1.f;
    LeCi_ps(1,2,0) = 1.f;
    LeCi_ps(2,0,1) = 1.f;
    LeCi_ps(1,0,2) = -1.f;
    LeCi_ps(2,1,0) = -1.f;
    LeCi_ps(0,2,1) = -1.f;

    return LeCi_ps;
}

static FASTOR_INLINE
Tensor<double,3,3,3> levi_civita_pd() {
    Tensor<double,3,3,3> LeCi_pd;
    LeCi_pd(0,1,2) = 1.;
    LeCi_pd(1,2,0) = 1.;
    LeCi_pd(2,0,1) = 1.;
    LeCi_pd(1,0,2) = -1.;
    LeCi_pd(2,1,0) = -1.;
    LeCi_pd(0,2,1) = -1.;

    return LeCi_pd;
}

//template<typename T>
//Tensor<T,3,3,3> levi_civita() {
//    Tensor<T,3,3,3> out; out.zeros();
//}

template<typename T, size_t ... Rest>
static FASTOR_INLINE
Tensor<T,Rest...> kronecker_delta() {
    Tensor<T,Rest...> out; out.eye();
    return out;
}

}

#endif // TENSOR_FUNCS_H

