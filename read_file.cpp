#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Eigen/Sparse>
typedef Eigen::SparseMatrix<double> SpMat; // declares a column-major sparse matrix type of double
typedef Eigen::Triplet<double> T;

int main(int argc, char** argv)
{
  int c,r;
  double v;
  std::vector<int> i;
  std::vector<int> j;
  std::vector<double> val;
  std::vector<T> trp;

  std::ifstream filename("mydata.dat");
  /*if (filename.good())
  {
    std::string sLine;
    int a,g;
    int h;
    getline(filename, sLine);
    std::cout << sLine << '\n';
  }*/
  int itr=0;
  if (filename.is_open()) {

    while (filename>>c>>r>>v) {
      itr = itr+1;
      if (itr==1){
        std::cout<<c<<r<<v<<"\n";
        Eigen::SparseMatrix<double> mat(r,v);
        //mat.reserve(Eigen::VectorXi::Constant(c,c/(r-5)));
        //i.push_back(c);
        //j.push_back(r);
        //val.push_back(v)
      }

      if (itr>=2){
        trp.push_back(T(c-1,r-1,v));
        //mat.insert(c-1,r-1)=v;
        //i.push_back(c);
        //j.push_back(r);
        //val.push_back(v);
      }
    }
    //std::cout << mat.rows() << '\n';
    filename.close();
  }
  SpMat mat(5,5);
  //mat.makeCompressed();
  //mat.reserve(nnz);
  mat.setFromTriplets(trp.begin(), trp.end());
  //std::cout << mat << '\n';
  return 0;
}
