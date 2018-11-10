#include <iostream>
#include <vector>
#include <Eigen/Sparse>
typedef Eigen::SparseMatrix<double> SpMat; // declares a column-major sparse matrix type of double
typedef Eigen::Triplet<double> T;

int main(int argc, char** argv)
{

  int nnz = 7;
  int row = 5, col = 5;
  int i[nnz] = {3, 4, 1, 2, 3, 1, 4};
  int j[nnz] = {1, 2, 3, 3, 4, 5, 5};
  double val[nnz] = {3, 6, 1, 9, 8, 2, 10};
  std::vector<int> veci (i, i + sizeof(i) / sizeof(i[0]) );
  std::vector<int> vecj (j, j + sizeof(j) / sizeof(j[0]) );
  std::vector<int> vecv (val, val + sizeof(val) / sizeof(val[0]) );
  int m,n;

  std::vector<T> trp;
  trp.reserve(nnz);
  //SpMat mat(row,col);
  for (m = 1;m<nnz+1;m++){
    trp.push_back(T(i[m-1]-1,j[m-1]-1,val[m-1]));
    //mat.insert(i[m-1]-1,j[m-1]-1)=val[m-1];
  }
  //trp.push_back(T(veci,vecj,vecv))
  SpMat mat(row,col);
  mat.reserve(nnz);
  mat.setFromTriplets(trp.begin(), trp.end());
  std::cout << mat  << '\n';
  std::cout << veci[1] << '\n';
  trp.clear();
  return 0;
}
