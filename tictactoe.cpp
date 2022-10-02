#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char penanda_sekarang;
int pemain_sekarang;

void drawBoard(){
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "__________\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "__________\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool Penanda(int slot){
    int row = slot / 3;
    int col;

    if(slot % 3 == 0) {
        row = row - 1;
        col = 2;
    }
    else {
        col = slot % 3 - 1;
    }
    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = penanda_sekarang;
        return true;
    } else {
        return false;
    }
}

int menang(){
    for(int i = 0; i < 3; i++)
{
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return pemain_sekarang;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return pemain_sekarang;
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
        return pemain_sekarang;
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
        return pemain_sekarang;
        }

    return 0;
  }
}

void ganti_pemain_n_tanda(){
    if(penanda_sekarang == 'O') penanda_sekarang = 'X';
    else penanda_sekarang = 'O';

    if(pemain_sekarang == 1) pemain_sekarang = 2;
    else pemain_sekarang = 1;

}

void game(){
    cout << "=============================================\n";
    cout << "           Permainan Tic Tac Toe                \n";
    cout << "=============================================\n";
    cout << "Pemain pertama, pilih penanda (X/O): ";
    char marker_p1;
    cin >> marker_p1;

    pemain_sekarang = 1;
    penanda_sekarang = marker_p1;

    drawBoard();

    int pemain_menang;

    for(int i = 0; i < 9; i++)
    {
        cout << "Giliran " << pemain_sekarang << " Masukkan slot: ";
        int slot;
        cin >> slot;

        if(slot < 1 || slot > 9) {
            cout << "Slot itu invalid! Pilih slot lain!\n"; i--; continue;
        }

        if(!Penanda(slot)) {
            cout << "Slot itu sudah dipakai! Pilih slot lain!\n"; i--; continue;
        }
        drawBoard();

        pemain_menang = menang();

        if(pemain_menang == 1)
        {
            cout << "Pemain pertama menang! Selamat!"; break;
        }
        if(pemain_menang == 2)
        {
            cout << "Pemain kedua menang! Selamat!"; break;
        }

        ganti_pemain_n_tanda();
    }

    if(pemain_menang == 0)
    {
        cout << "Seri!";
    }
}

int main(){

    game();
}
