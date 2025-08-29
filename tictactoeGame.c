//1. TIC-TAC-TOE
#include <stdio.h> //library untuk scanf printf puts

char board[3][3]; //buat wadah XO
char currentPlayer = 'X'; //membuat wadah untuk current player
//kenapa void? karena hanya berisi method
void initBoard(){ //Function untuk ga ada jawaban X maupun O 
	for(int i = 0; i < 3; i++){ //Nested Loop
		for(int j = 0; j < 3; j++){
			board[i][j] = ' '; //Inisialisasi ke 0 semuanya
		}
	}
}

//kenapa void? karena hanya berisi method
void printBoard(){ //Print output grid TicTacToe
	printf("\n"); //mau cetak empty space sebelum grid 
	for(int i = 0; i < 3; i++){ //Selama i iterasi sampai 3x
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]); //i nya berubah dari 0,1,2 biar rownya beda2
		if(i < 2){
			printf("---|---|---\n"); 
		}
	}
	printf("\n"); //mau cetak empty space setelah grid	
}

//kenapa int bukan void? Karena dia mau return sesuatu sebagai penanda menang/kalah.
int isWin(char player){ //Function buat show itu win. Kenapa ada parameter? Karena butuh input user.
	for(int i = 0; i < 3; i++){ //loop ini hanya berlaku untuk yang horizonal & vertikal, diagonal ga butuh.
		if((board[i][0] == player && board[i][1] == player && board[i][2] == player) || //ini untuk baris X atau O berturut2
		   (board[0][i] == player && board[1][i] == player && board[2][i] == player)){//ini untuk kolom X atau O berturut2
		   return 1; //(1) = isWin()
	       }
	}
	if((board[0][0] == player && board[1][1] == player && board[2][2] == player) || //ini cek diagonal
	   (board[0][2] == player && board[1][1] == player && board[2][0] == player)){
	   return 1; //(1) = isWin()		   	
	   }
	return 0; //(0) tidak termasuk ke dalam block int main, yang masuk itu 1.
	//inti nya, mau return 1,2,3 atau apapun itu, bisa ada dalam satu function. 
	//Misalnya return 1 untuk horizontal vertical, return 2 untuk diagonal
	//di int main nanti, if(hasil == 1), win hori/verti... if(hasil ==1), win diagonal
}

int isDraw(){//Function untuk cek apakah X dan O ini nilainya sama / seimbang
	for (int i = 0; i < 3; i++){ //nested loop
        for (int j = 0; j < 3; j++){
            if (board[i][j] == ' '){ //kalau sebuah bagian belum terisi, maka dia fail dijalankan.
        	    return 0; //menunjukkan kondisi yang false sehingga di int main tidak dijalankan
		    }
	    }
    }
    return 1; //me-return sebuah value yaitu 1, jika memang isDraw().
}

void switchPlayer(){ //Function untuk menukar pemain
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; //Trenary operator: (condition) ? value_if_true : value_if_false;
	                 //Apakah 'X' karakternya? Kalau yes, maka switch jadi 'O'. 
	                 //Apakah 'O' sekarang karakternya? Kalau yes, switch jadi 'X';
}

int main(){ //buat ngejalanin semua codingannya
	int row, col; //ini wadah untuk nampung output row & col
	initBoard(); //set ke 0 dulu
	
    while (1) { //selama kondisi selalu benar. (1) adalah selalu benar, akan selalu di loop sampai ada break;
        printBoard(); //selama kondisi benar, printBoard/
        printf("Player %c, enter row and column (1-3): ", currentPlayer); //selama kondisi benar, minta user input angka (1-3)
        scanf("%d %d", &row, &col); //selama kondisi benar, input row, input column. 

        row--; col--; // Biar dari index 0, jadi mau kurangin inputan user dengan 1.
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') { //Habis terima input row, column, mikir, kalau
        //user inputnya aneh2 gimana. Jadi kalau kurang dari 0 atau lebih dari 2, serta slot udah terisi sebelumnya:
            printf("Invalid move! Try again.\n"); //gagal
            continue;//langsung skip line code di bawah (yg masih dalam cakupan while), jadi dia keulang dari while kembali.
        }
        
        board[row][col] = currentPlayer; //[row] & [col] isinya itu adalah 'X' dari currentPlayer

        if (isWin(currentPlayer)) { //kalau isWin(currentPlayer) benar karena return 1 yang berarti ada 3 yang sama XXX OOO
            printBoard(); //Maka akan print board : garis & isi char di dalam kotak. 
            printf("Player %c wins!\n", currentPlayer); //output kalau player 'X' menang 
            break; //out dari while loop. Operasi berakhir.
        } else if (isDraw()) { //kalau isDraw(1) dalam arti return 1 itu true dia draw..
            printBoard(); //print board : garis & isi char di dalam kotak. 
            printf("It's a draw!\n"); //output draw, menandakan dia ada isinya. Setiap box yang ada isi kalau gak menang, namanya isDraw.
            break; //out dari while loop. Operasi berakhir.
        }
        
        //panggil ke atas.
        switchPlayer(); //habis input[row][col] , kita mau switch player kedua untuk input, tadi X' sekarang 'O'.
    }
	return 0; //program selesai dengan sukses
}
