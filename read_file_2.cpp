#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <Eigen/Sparse>

using namespace std;
typedef Eigen::SparseMatrix<double> SpMat; // declares a column-major sparse matrix type of double

int main(int argc, char** argv)
{
  int c,r,itr;
  double v;
  vector<int> i,j;
  vector<double> val;

  ifstream bucky;
  bucky.open("mydata.dat");

  if(!bucky.is_open()){
    exit(EXIT_FAILURE);/**/
  }

  int nnz, n, m;
  bucky >>nnz>>m>>n;
  cout<<nnz<<m<<n<<"\n";
  SpMat mat(m,n);
  mat.reserve(nnz);
  itr = 0;
  while (bucky>>c>>r>>v) {
    itr = itr+1;
    if (itr>=2){
      mat.insert(c-1,r-1)=v;
    }
  }
  bucky.close();
  std::cout << mat << '\n';
  return 0;
}
