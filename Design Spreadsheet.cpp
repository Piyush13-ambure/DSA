/*A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.

Implement the Spreadsheet class:

Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
void resetCell(String cell) Resets the specified cell to 0.
int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered */

class Spreadsheet {
public:
    using int2=pair<short, char>;
    int A[1000][26];
    int rows;
    Spreadsheet(int rows) : rows(rows) {
        memset(A, 0, rows*26*sizeof(int));
    }

    int2 idx(const string& cell){
        char col=cell[0]-'A';
        short row=stoi(cell.substr(1))-1;
        return {row, col};
    }
    void setCell(const string& cell, int value) {
        A[idx(cell).first][idx(cell).second]=value;
    }
    
    void resetCell(const string& cell) {
        A[idx(cell).first][idx(cell).second]=0;
    }
    
    int getValue(const string& formula) {
        int m=formula.find('+');
        int x, y;
        const string xx=formula.substr(1, m-1), yy=formula.substr(m+1);
        if (formula[1]>='A') 
            x=A[idx(xx).first][idx(xx).second];
        else x=stoi(xx);
        if (formula[m+1]>='A') 
            y=A[idx(yy).first][idx(yy).second];
        else y=stoi(yy);
        return x+y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
