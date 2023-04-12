#ifndef ITER_HPP
#define ITER_HPP

/* ========================================================================== */
/*                                     T                                      */
/* ========================================================================== */
template <typename T>
void iter(T *array, int length, void (*f)(T)) {
  for (int i = 0; i < length; i++) f(array[i]);
}

/* ========================================================================== */
/*                                 const T                                    */
/* ========================================================================== */
template <typename T>
void iter(const T *array, int length, void (*f)(const T)) {
  for (int i = 0; i < length; i++) f(array[i]);
}

/* ========================================================================== */
/*                              reference of T                                */
/* ========================================================================== */
template <typename T>
void iter(T *array, int length, void (*f)(T &)) {
  for (int i = 0; i < length; i++) f(array[i]);
}

/* ========================================================================== */
/*                          const reference of T                              */
/* ========================================================================== */
template <typename T>
void iter(const T *array, int length, void (*f)(T const &)) {
  for (int i = 0; i < length; i++) f(array[i]);
}
#endif
