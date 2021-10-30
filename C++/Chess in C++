#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct ChessBoard{
    enum class Turn {white, black} turn;
    enum class Piece {king, queen, white_pawn, black_pawn, rook, bishop, knight};
    static map<Piece,int> pieceValues;
    bool show_coordinates = false;

    struct Pos{
        int x,y;
        Pos(const Pos &p, int dx=0, int dy=0){ *this = p; x+=dx; y+=dy;}
        Pos(int _x, int _y){  x=_x; y=_y; }
        bool operator<(const Pos & p) const { return (x < p.x) || (x==p.x && y < p.y); }
        bool operator==(const Pos & p) const { return x==p.x && y==p.y; }
        Pos(){x=-1;y=-1;}
    };

    map<Pos,Piece> white_pieces, black_pieces;
    map<Pos,Piece> & moverPieces(){ return turn == Turn::white ? white_pieces : black_pieces; }
    map<Pos,Piece> & opponentPieces(){ return turn == Turn::white ? black_pieces : white_pieces; }

    void reset(){
        turn = Turn::white;
        white_pieces.clear();
        black_pieces.clear();
        for(int i=1; i < 9; ++i){
            white_pieces[Pos(i,7)]=Piece::white_pawn;
            black_pieces[Pos(i,2)]=Piece::black_pawn;
        }
        int n=1;
        for(auto piece : {Piece::rook,Piece::knight,Piece::bishop,Piece::king}){
            white_pieces[Pos(n,8)]=white_pieces[Pos(9-n,8)]=black_pieces[Pos(n,1)]=black_pieces[Pos(9-n,1)]=piece;
            ++n;
        }
        white_pieces[Pos(4,8)]=black_pieces[Pos(4,1)]=Piece::queen;
    }

    void flipTurn(){ turn = turn == Turn::white? Turn::black : Turn::white; }

    bool makeMove(Pos from, Pos to){
        vector<Pos> allowed = possibleMoves(from);
        if(find(allowed.begin(), allowed.end(), to) == allowed.end())
            return false;
        opponentPieces().erase(to);
        moverPieces()[to]=moverPieces()[from];
        moverPieces().erase(from);
        if((moverPieces()[to]==Piece::white_pawn || moverPieces()[to]==Piece::black_pawn) && (to.y == 1 || to.y == 8))
            moverPieces()[to]=Piece::queen;
        flipTurn();
        return true;
    }

    vector<Pos> possibleMoves(const Pos & from){
        vector<Pos> moves;
        auto isOwn = [&] (int dx, int dy) -> bool { return moverPieces().count(Pos(from,dx,dy));};
        auto isOpponent = [&] (int dx, int dy) -> bool { return opponentPieces().count(Pos(from,dx,dy));};
        auto isInsideBoard = [&] (int dx, int dy) -> bool { Pos p(from,dx,dy); return p.x < 9 && p.x > 0 && p.y < 9 && p.y > 0; };
        auto isFree = [&] (int dx, int dy) -> bool { return !isOwn(dx,dy) && isInsideBoard(dx,dy) && !isOpponent(dx,dy); };

        auto addMove = [&] (int dx, int dy) -> bool {
            if(isFree(dx,dy) || isOpponent(dx,dy)){
                moves.push_back(Pos(from,dx,dy));
                return true;
            }
            return false;
        };

        if(!isOwn(0,0))
            return moves;

        auto moving_piece = moverPieces()[from];
        switch(moving_piece){
            case Piece::white_pawn:
                if(isFree(0,-1)) addMove(0,-1);
                if(isFree(0,-1) && isFree(0,-2) && from.y==7) addMove(0,-2);
                if(isOpponent(-1,-1)) addMove(-1,-1);
                if(isOpponent(1,-1)) addMove(1,-1);
                break;

            case Piece::black_pawn:
                if(isFree(0,1)) addMove(0,1);
                if(isFree(0,1) && isFree(0,2) && from.y==2) addMove(0,2);
                if(isOpponent(-1,1)) addMove(-1,1);
                if(isOpponent(1,1)) addMove(1,1);
                break;

            case Piece::knight:
                addMove(-2,-1); addMove(-2,1); addMove(2,-1); addMove(2,1);
                addMove(-1,-2); addMove(-1,2); addMove(1,-2); addMove(1,2);
                break;

            case Piece::king:
                for(auto dy : {-1,0,1})
                for(auto dx : {-1,0,1})
                addMove(dy,dx);
                break;

            case Piece::queen:
            case Piece::rook:
                for(int n=1; n < 9 && addMove(0,n) && !isOpponent(0,n); ++n);
                for(int n=1; n < 9 && addMove(0,-n) && !isOpponent(0,-n); ++n);
                for(int n=1; n < 9 && addMove(n,0) && !isOpponent(n,0); ++n);
                for(int n=1; n < 9 && addMove(-n,0) && !isOpponent(-n,0); ++n);
                if(moving_piece != Piece::queen)
                    break;

            case Piece::bishop:
                for(int n=1; n < 9 && addMove(n,n) && !isOpponent(n,n); ++n);
                for(int n=1; n < 9 && addMove(n,-n) && !isOpponent(n,-n); ++n);
                for(int n=1; n < 9 && addMove(-n,n) && !isOpponent(-n,n); ++n);
                for(int n=1; n < 9 && addMove(-n,-n) && !isOpponent(-n,-n); ++n);
                break;
        }

        return moves;
    }

    void printBoard(){
        static map<Piece, char> sprites =
         { {Piece::white_pawn,'P'}, {Piece::black_pawn,'P'}, {Piece::rook,'H'}, {Piece::knight,'F'},
            {Piece::bishop,'I'}, {Piece::king,'K'}, {Piece::queen,'Q'} };
        cout<<endl<<"        1     2     3     4     5     6     7     8   "<<endl;
        cout<<"      _____ _____ _____ _____ _____ _____ _____ _____ ";
        for(int y=1; y < 9; ++y){
            if(show_coordinates)
                cout<<endl<<"     |1"<<y<<"   |2"<<y<<"   |3"<<y<<"   |4"<<y<<"   |5"<<y<<"   |6"<<y<<"   |7"<<y<<"   |8"<<y<<"   |";
            else
                cout<<endl<<"     |     |     |     |     |     |     |     |     |";
            cout<<endl<<"  "<<y<<"  ";
            for(int x=1; x < 9; ++x){
                cout<<"|  ";
                if(white_pieces.count(Pos(x,y)))
                    cout<<sprites[white_pieces[Pos(x,y)]];
                else if(black_pieces.count(Pos(x,y)))
                    cout<<(char)tolower(sprites[black_pieces[Pos(x,y)]]);
                else 
                    cout<<" ";
                cout<<"  ";
            }
            cout<<"|  "<<y<<endl<<"     |_____|_____|_____|_____|_____|_____|_____|_____|";
        }
        cout<<endl<<endl<<"        1     2     3     4     5     6     7     8   "<<endl<<endl;
    }

    void printHelp(){
        cout<<endl<<"* h: help, q: quit, p: show board, c: toggle show coordinates inside squares"<<endl<<"* Input format: yxyx is from-to coordinates, e.g: 1715 moves (x,y)=(1,7) to (x,y)=(1,5)"<<endl<<endl;
    }

    /* False to exit */
    bool promptInput(){
        string move;
        illegalmove:
        if(turn==Turn::white)
            cout<<"White move: ";
        else
            cout<<"Black move: ";
        if(move == "")
            cin>>move;
        if(move == "q"){
            cout<<"Good bye"<<endl<<endl;
            return false;
        }
        if(move == "?" || move == "h" || move == "help"){
            printHelp();
            move="";
            goto illegalmove;
        }
        if(move == "c"){
            show_coordinates = !show_coordinates;
            printBoard();
            move="";
            goto illegalmove;
        }

        if(move == "p"){
            printBoard();
            move="";
            goto illegalmove;
        }
        Pos from(-1,-1),to(-1,-1);
        if(move.length() == 4){
            from.x = move[0] - '0';
            from.y = move[1] - '0';
            to.x = move[2] - '0';
            to.y = move[3] - '0';
        }
        if(!makeMove(from,to)){
            cout<<"* Illegal move"<<endl;
            move = "";
            goto illegalmove;
        }
        printBoard();
        return true;
    }

    int score(){
        int sumWhite = 0;
        for(auto & p : white_pieces)
            sumWhite += pieceValues[p.second];
        int sumBlack = 0;
        for(auto & p : black_pieces)
            sumBlack += pieceValues[p.second];
        return sumWhite-sumBlack;
    }

    bool hasKing(){
        for(auto & p : moverPieces())
            if(p.second == Piece::king)
                return true;
        return false;
    }

    struct Move{
        Pos from,to;
        int score;
    };

    Move minimax(int depth, bool minimize){
        Move best_move;
        best_move.score = -1000000 + 2000000*minimize;
        if(0 == depth){
            best_move.score = score();
            return best_move;
        }

        for(auto & from : moverPieces()){
            for(auto & to : possibleMoves(from.first)){
                ChessBoard branch = *this;
                branch.makeMove(from.first,to);
                Move option = branch.minimax(depth-1, !minimize);
                if((option.score > best_move.score && !minimize) || (option.score < best_move.score && minimize)){
                    best_move.score = option.score;
                    best_move.from = from.first;
                    best_move.to = to;
                }
            }
        }
        return best_move;
    }

    void AIMove(){
        bool minimize = turn == Turn::black ? true : false;
        Move m = minimax(4,minimize);
        makeMove(m.from,m.to);
        printBoard();
    }
};

map<ChessBoard::Piece,int> ChessBoard::pieceValues {{ChessBoard::Piece::king, 10000},
{ChessBoard::Piece::queen, 9}, {ChessBoard::Piece::black_pawn, 1}, {ChessBoard::Piece::white_pawn, 1},
{ChessBoard::Piece::bishop, 3},{ChessBoard::Piece::knight, 3},{ChessBoard::Piece::rook, 5},};

main(){
    ChessBoard game;
    cout<<endl<<"* Chesscomputer v.0.1"<<endl;
    game.printHelp();
    bool gameon=true;
    while(gameon){
        game.reset();
        string pick_side = "";
        while(pick_side != "b" && pick_side != "w" && pick_side != "q"){
            cout<<endl<<"Play as (b)lack or (w)hite or (q)uit? ";
            cin>>pick_side;
        }
        if(pick_side == "q"){
            cout<<"Good bye."<<endl;
            break;
        }

        if(pick_side == "b")
            game.AIMove();
        else
            game.printBoard();

        while(gameon = game.promptInput()){
            if(!game.hasKing()){
                cout<<"* You are victorious!"<<endl;
                break;
            }
            game.AIMove();
            if(!game.hasKing()){
                cout<<"* You are defeated!"<<endl;
                break;
            }
        }
    }
    return 0;   
}
