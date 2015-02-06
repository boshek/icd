// [[Rcpp::interfaces(r, cpp)]]
#include <Rcpp.h>
using namespace Rcpp;

std::string trimRight(std::string& s) {
  std::size_t n = s.find_last_not_of(" \f\n\r\t\v");
  s.erase(n + 1);
  return s;
}

std::string trimLeft(std::string& s) {
  std::size_t n = s.find_first_not_of(" \f\n\r\t\v");
  s.erase(0, n);
  return s;
}

// [[Rcpp::export]]
std::string strim_cpp(std::string& s) {
  trimLeft(s);
  trimRight(s);
  return s;
}

// [[Rcpp::export]]
std::vector<std::string > trim_cpp(std::vector<std::string >& sv) {
  for (std::vector<std::string >::iterator i = sv.begin(); i != sv.end(); ++i) {
    strim_cpp(*i);
  }
  return sv;
}

#ifdef ICD9_DEBUG
void printVecStr(VecStr sv) {
  for (VecStrIt i=sv.begin(); i!=sv.end(); ++i) {
    std::cout << *i << ", ";
  }
  std::cout << "\n";
  return;
}

void printSetStr(SetStr vs) {
  for (SetStr::iterator i=vs.begin(); i!=vs.end(); ++i) {
    std::cout << *i << ", ";
  }
  std::cout << "\n";
  return;
}

void printCharVec(CharacterVector cv) {
  for (CharacterVector::iterator i = cv.begin(); i != cv.end(); ++i) {
    String s = *i;
    std::cout << s.get_cstring() << ", ";
  }
  std::cout << "\n";
  return;
}
#endif
