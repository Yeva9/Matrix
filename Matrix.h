#pragma <once> 
#include <iostream> 
using namespace std; 
class Matrix 
{ 
//qani vor "cout<<a" operatori dzakh op-y cout-n e(kam ciny) => sa chenq karogh
//gerbernel vorpes member function(vorpes klassi andam f-a), bayc vorpeszi ays klassi mijiny
//karoghananq cout(kam cin) anel petq e hasaneli+ unenanq => ays op-y friend f-a e
friend std::ostream& operator<<(std::ostream&, const Matrix&);//cout-y ostream` output stream(elqayin hosq) tipi e,
                                                              //&` vortev mejy ban enq grelu, const&-ov` 
                                                              //qanivor cout aneluc pokhelu npatak chunenq
friend std::istream& operator>>(std::istream&, Matrix&);//input stream(mutqayin hosq) tipi e,
                                                        //2-dr arg-y voch const e q.v. pokhevelu e
    
public: 
Matrix(int, int); 
Matrix(int, int, const int**); 
Matrix(const Matrix &); 
~Matrix(); 

int get_rows() const {return m_rows;} 
int get_columns() const {return m_columns;} 
void add_row(const int*, int); 
void remove_row(int); 
int get_element(int,int) const; 
int get_max() const; 
void print() const; 

//operatorner kan voronq classic durs chenq karogh grel. or.` =(veragrumy) qani vor 
// *this er veradardznum (bolor veragrumnery aydpisin en), aysinqn `+=-y classi mej
//kgrenq isk +y kartahaytenq sranov(x+=y aveli optimal e qan x=x+y): 
//op-ery karogh enq gerbernel ev global ev local tir-um bayc or. || u && y 
//chisht chi ashkhatum yete menq enq gerbernum => && || u , op-ery khusapenq ogt-el 
Matrix& operator=(const Matrix&); 
bool operator==(const Matrix&) const;//& copy chkanchelu hamar enq grum 
Matrix& operator +=(const Matrix&);//1i &` qani vor veragrman op-i nman veradardznelu e ir 
                                   //dzakh operandy(thisy), const che qani vor pokhvelu e 
Matrix& operator -=(const Matrix&);
Matrix& operator *=(const Matrix&);
Matrix& operator /=(const Matrix&);
Matrix& operator %=(const Matrix&);
Matrix& operator <<=(const Matrix&);
Matrix& operator >>=(const Matrix&);
int& operator()(int,int);//qani vor []-opy mi argument e stanum => chenq karogh [i,j]-n
                         //grel => gerbernenq (i,j), &` qani vor hakarak depqum inch-vor 
                         //arzheqi copy e veradardznelu u ayd depqum iren vochinch chenq 
                         //karogh veragrel, vorpeszi karogh. veragrel => & e petq 
const int& operator()(int,int) const;//const f-a e vorin vochinch chenq karogh veragrel, 
                                     //dra hamar verevi tarberakn el enq grum vor 
                                     //karoghananq veragrel[i][j]-in(const A[i][j]-in)


private: 
  //new-i u delete-i func-ery aystegh grenq qani vor drsic kanchelu npatak chka 
  void allocate();//new 
  void dellocate();//delete 

  int m_rows; 
  int m_columns; 
  int ** m_matrix; 
}; 

bool operator!=(const Matrix&, const Matrix&); 

Matrix operator+(Matrix, const Matrix&); 
Matrix operator-(Matrix, const Matrix&);
Matrix operator*(Matrix, const Matrix&);
Matrix operator/(Matrix, const Matrix&);
Matrix operator%(Matrix, const Matrix&);
Matrix operator<<(Matrix, const Matrix&);
Matrix operator>>(Matrix, const Matrix&);
