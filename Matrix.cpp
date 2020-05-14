#include "Matrix.h"

std::ostream& operator<<(std::ostream& o, const Matrix& M)
{
    for(int i = 0; i < M.m_rows; ++i)
   {
       for(int j = 0; j < M.m_columns; ++j)
       o<<M.m_matrix[i][j]<<' ';
       //m_matrix-y private e u cheinq karogh dimel ete friend chliner
   o<<endl;
   }
   return o;
}

std::istream& operator>>(std::istream& k, Matrix& M)
{
    for(int i = 0; i < M.m_rows; ++i)
        for(int j = 0; j < M.m_columns; ++j)
            k>>M.m_matrix[i][j];
      
      return k;
}

void Matrix:: allocate() 
{ 
m_matrix = new int*[m_rows]; 
for(int i = 0; i < m_rows; ++i) 
m_matrix[i] = new int [m_columns]; 
} 

void Matrix:: dellocate() 
{ 
for(int i = 0; i < m_rows; ++i) 
delete [] m_matrix[i]; 
delete [] m_matrix; 
} 

Matrix::Matrix(int m, int n) 
:m_rows(n) 
,m_columns(m) 
{ 
allocate(); 
for(int i = 0; i < n; ++i) 
    for(int j = 0; j < m; ++j) 
        m_matrix[i][j] = 0; 
} 

Matrix::Matrix(int n, int m, const int** matrix) 
:m_rows(n) 
,m_columns(m) 
{ 
allocate(); 
for(int i = 0; i < n; ++i) 
    for(int j = 0; j < m; ++j) 
        m_matrix[i][j] = matrix[i][j]; 
} 

Matrix::Matrix(const Matrix& m) 
:m_rows(m.m_rows) 
,m_columns(m.m_columns) 
{ 
allocate(); 
for(int i = 0; i < m_rows; ++i) 
    for(int j = 0; j < m_columns; ++j) 
        m_matrix[i][j] = m.m_matrix[i][j]; 
} 

Matrix:: ~Matrix() 
{ 
dellocate(); 
} 

void Matrix::add_row(const int* A, int k) //A-n ekats toghn e 
{ 
int ** A1 = new int * [m_rows +1]; 
for(int j = 0; j < k; ++j)//0ic k sagh copy arecinq 
{ 
A1[j] = m_matrix[j]; 
} 

A1[k] = new int [m_columns];//k-rd y new arecinq u mez ekatsyay A1-um grecinq
for(int j = 0; j < m_columns; ++j) 
A1[k][j] = A[j]; 

for(int j = 0; j < m_rows +1; ++j) 
A1[j] = m_matrix[j]; 
++m_rows; 
delete []m_matrix; 
m_matrix = A1; 
} 

void Matrix:: remove_row(int i) 
{ 
int ** A1 = new int * [m_rows-1]; 
for(int j = 0; j < i; ++j) 
{ 
    A1[j] = m_matrix[j]; 
} 
delete []m_matrix; 
m_matrix = A1; 
} 

int Matrix::get_element(int i,int j) const 
{ 
return m_matrix[i][j]; 
} 

int Matrix::get_max() const 
{ 
int max = 0; 
max = m_matrix[0][0]; 

for (int i = 0; i < m_rows; ++i) 
    for (int j = 0; j < m_columns; ++j) 
        if(m_matrix[i][j] > max) 
        { 
            max = m_matrix[i][j]; 
        } 
return max; 
} 

void Matrix:: print() const 
{ 
for (int i = 0; i < m_rows; ++i) 
{ 
    for (int j = 0; j < m_columns; ++j) 
    cout << m_matrix[i][j] << ' '; 
cout << endl; 
} 
cout << endl; 
} 

Matrix& Matrix:: operator=(const Matrix &M) 
{ 
if(&M != this)//hascenery hamematenq(*this-y arden Matrix tipi e isk henc this-y pointer e 
{ 
dellocate(); 
m_rows = M.m_rows; 
m_columns = M.m_columns; 
allocate(); 

for(int i = 0; i < m_rows; ++i) 
    for(int j = 0; j < m_columns; ++j) 
        m_matrix[i][j] = M.m_matrix[i][j]; 
} 
return *this;// parunakutyuny, aysinqn amboghj matricy` el-erov, chapov ev ayln
} 

bool Matrix::operator==(const Matrix& M) const 
{ 
if( m_rows != M.m_rows || m_columns != M.m_columns) return false; 
for(int i = 0; i < m_rows; ++i) 
    for(int j = 0; j < m_columns; ++j) 
    { 
        if(m_matrix[i][j] != M.m_matrix[i][j]) 
        return false; 
    } 
return true; 
} 

bool operator!=(const Matrix& M1, const Matrix& M2)//global f-a e dra hamar Matrix:: chenq grum 
{ 
return !(M1==M2); 
} 

Matrix& Matrix:: operator+=(const Matrix& M)//this-i het enq ashkhatelu,petq e this-y
                                             //pokhenq u amen dashty += anenq 
{ 
//M-i rows u columnsy petq e = linen mer m_mcol u m_row-in 
if( m_rows == M.m_rows && m_columns == M.m_columns) 
{ 
    for(int i = 0; i < m_rows; ++i) 
        for(int j = 0; j < m_columns; ++j) 
        { 
            m_matrix[i][j] +=M.m_matrix[i][j]; 
        } 
} 
return *this; 
} 

Matrix& Matrix::operator-=(const Matrix& M)
{
    if(m_rows == M.m_rows && m_columns == M.m_columns)
    {
        for(int i = 0; i < m_rows; ++i)
            for(int j = 0; j < m_columns; ++j)
            m_matrix[i][j]-=M.m_matrix[i][j];
   }
   return *this;
}

Matrix& Matrix::operator *=(const Matrix& M)
{
    if(m_rows == M.m_rows && m_columns == M.m_columns)
    {
        for(int i = 0; i < m_rows; ++i)
            for(int j = 0; j < m_columns; ++j)
            m_matrix[i][j]*=M.m_matrix[i][j];
    }
    return *this;
}


Matrix& Matrix:: operator /=(const Matrix& M)
{
    if( m_rows == M.m_rows && m_columns == M.m_columns)
    {
         for(int i = 0; i < m_rows; ++i)
            for(int j = 0; j < m_columns; ++j)
            m_matrix[i][j]/=M.m_matrix[i][j];
    }
    return *this;
}

Matrix& Matrix:: operator %=(const Matrix& M)
{
     if( m_rows == M.m_rows && m_columns == M.m_columns)
    {
         for(int i = 0; i < m_rows; ++i)
            for(int j = 0; j < m_columns; ++j)
            m_matrix[i][j]%=M.m_matrix[i][j];
    }
    return *this;
}

Matrix operator+(Matrix x, const Matrix& y)//veradardzvogh arzheqy nor matric enq stanum=> 
                                           //vochinch chenq karogh veragrel => & che 
//x-y voch const e, voch &` aysinqn copyn klini, erkrordy` chenq pokhelu(xy pokhvum e y-y che) 
{ 
return x+=y;//+= i ardyunqy &x er, sa copy enq anum u veradardznum(normal e vor copy veradardzni
            //qani vor nerdrvats += y evs inchvor banic copy e eghel) 
            //+= y matrix& e veradardznelu, this-i vra hghum e => copy kani u durs kta 
} 
/*kam,ete const u & hanenq ays hamarzheq f-n kstananq 
Matrix operator+(const Matrix& x, const Matrix& y) 
{ 
Matrix z(x);//nor matric sarqenq`z, vory x-i copyn e 
z+=y; 
return z; 
}*/ 

Matrix operator-(Matrix M1, const Matrix& M2)
{
    return M1-=M2;
}

Matrix operator*(Matrix M1, const Matrix& M2)
{
    return M1*=M2;
}

Matrix operator/(Matrix M1, const Matrix& M2)
{
    return M1/=M2;
}

Matrix operator%(Matrix M1, const Matrix& M2)
{
    return M1%=M2;
}

Matrix& Matrix::operator <<=(const Matrix& M)
{
    if(m_rows == M.m_rows && m_columns == M.m_columns)
    {
        for(int i = 0; i < m_rows; ++i)
            for(int j = 0; j < m_columns; ++j)
            m_matrix[i][j]<<=M.m_matrix[i][j];
    }
    return *this;
}

Matrix& Matrix::operator >>=(const Matrix& M)
{
    if(m_rows == M.m_rows && m_columns == M.m_columns)
    {
        for(int i = 0; i < m_rows; ++i)
            for(int j = 0; j < m_columns; ++j)
            m_matrix[i][j]>>=M.m_matrix[i][j];
    }
    return *this;
}

Matrix operator<<(Matrix M1, const Matrix& M2)
{
    return M1<<=M2;
}


Matrix operator>>(Matrix M1, const Matrix& M2)
{
    return M1>>=M2;
}

int& Matrix:: operator()(int i,int j)
{
    return m_matrix[i][j];    
}

const int& Matrix:: operator()(int i,int j) const
{
    return m_matrix[i][j];
}

int main() 
{ 

 /*Matrix B(3,3);
 B.print();
 cout << B.get_rows() << ' ' << B.get_columns() << ' ' << B.get_max() << ' ' << B.get_element(1,1) << ' ';*/ 
     
  /*Matrix M(3,3);
  cout << M << endl;
  cin >> M;
  cout << endl << M;*/
      
     return 0;

}
