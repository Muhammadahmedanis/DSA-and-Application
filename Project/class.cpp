        // #include <bits/stdc++.h>
        // #include <windows.h> // For system("cls") and Sleep()
        // using namespace std;

        // struct Cell {
        //     bool hasMine = false;
        //     bool uncovered = false;
        //     bool flagged = false;
        //     int neighborMines = 0;
        // };

        // class Minesweeper {
        // private:
        //     int rows, cols, mineCount;
        //     vector<vector<Cell>> board;
        //     int cellsUncovered = 0;
        //     bool gameOver = false;

        //     bool inBounds(int r, int c) {
        //         return r >= 0 && r < rows && c >= 0 && c < cols;
        //     }

        //     void placeMines() {
        //         vector<int> indices(rows * cols);
        //         iota(indices.begin(), indices.end(), 0);
        //         shuffle(indices.begin(), indices.end(), mt19937(random_device()()));
        //         for (int i = 0; i < mineCount; i++) {
        //             int r = indices[i] / cols;
        //             int c = indices[i] % cols;
        //             board[r][c].hasMine = true;
        //         }
        //     }

        //     void computeNeighborCounts() {
        //         int dr[8] = {-1,-1,-1,0,0,1,1,1};
        //         int dc[8] = {-1,0,1,-1,1,-1,0,1};
        //         for (int r = 0; r < rows; r++) {
        //             for (int c = 0; c < cols; c++) {
        //                 if (board[r][c].hasMine) continue;
        //                 int count = 0;
        //                 for (int i = 0; i < 8; i++) {
        //                     int nr = r + dr[i], nc = c + dc[i];
        //                     if (inBounds(nr, nc) && board[nr][nc].hasMine)
        //                         count++;
        //                 }
        //                 board[r][c].neighborMines = count;
        //             }
        //         }
        //     }

        //     void displayBoard(bool revealAll = false) {
        //         system("cls");
        //         cout << "   ";
        //         for (int c = 0; c < cols; c++) cout << setw(2) << c << " ";
        //         cout << "\n  +";
        //         for (int c = 0; c < cols; c++) cout << "---";
        //         cout << "+\n";

        //         for (int r = 0; r < rows; r++) {
        //             cout << setw(2) << r << "|";
        //             for (int c = 0; c < cols; c++) {
        //                 Cell &cell = board[r][c];
        //                 if (revealAll || cell.uncovered) {
        //                     if (cell.hasMine) cout << " * ";
        //                     else if (cell.neighborMines > 0) cout << " " << cell.neighborMines << " ";
        //                     else cout << " . ";
        //                 } else if (cell.flagged) {
        //                     cout << " F ";
        //                 } else {
        //                     cout << " # ";
        //                 }
        //             }
        //             cout << "|\n";
        //         }

        //         cout << "  +";
        //         for (int c = 0; c < cols; c++) cout << "---";
        //         cout << "+\n";

        //         cout << "Uncovered: " << cellsUncovered << "/" << (rows * cols - mineCount)
        //             << " | Flags: " << countFlags()
        //             << " | Mines: " << mineCount << "\n";
        //     }

        //     int countFlags() {
        //         int cnt = 0;
        //         for (auto &row : board)
        //             for (auto &cell : row)
        //                 if (cell.flagged) cnt++;
        //         return cnt;
        //     }

        //     void revealAllMines() {
        //         for (auto &row : board)
        //             for (auto &cell : row)
        //                 if (cell.hasMine) cell.uncovered = true;
        //     }

        //     int uncoverRegion(int sr, int sc) {
        //         if (!inBounds(sr, sc) || board[sr][sc].uncovered || board[sr][sc].flagged || board[sr][sc].hasMine)
        //             return 0;

        //         int count = 0;
        //         queue<pair<int, int>> q;
        //         q.push({sr, sc});
        //         board[sr][sc].uncovered = true;
        //         count++;

        //         int dr[8] = {-1,-1,-1,0,0,1,1,1};
        //         int dc[8] = {-1,0,1,-1,1,-1,0,1};

        //         while (!q.empty()) {
        //             auto [r, c] = q.front(); q.pop();
        //             if (board[r][c].neighborMines != 0) continue;

        //             for (int i = 0; i < 8; i++) {
        //                 int nr = r + dr[i], nc = c + dc[i];
        //                 if (inBounds(nr, nc) && !board[nr][nc].uncovered && !board[nr][nc].flagged) {
        //                     board[nr][nc].uncovered = true;
        //                     count++;
        //                     if (board[nr][nc].neighborMines == 0) {
        //                         q.push({nr, nc});
        //                     }
        //                 }
        //             }
        //         }
        //         return count;
        //     }

        // public:
        //     Minesweeper(int r, int c, int m) : rows(r), cols(c), mineCount(m) {
        //         board.assign(rows, vector<Cell>(cols));
        //         placeMines();
        //         computeNeighborCounts();
        //     }

        //     void run() {
        //         while (!gameOver) {
        //             displayBoard();
        //             cout << "Enter move (u r c to uncover, f r c to flag, q to quit): ";
        //             char action;
        //             int r, c;
        //             string line;
        //             getline(cin >> ws, line);
        //             istringstream iss(line);
        //             iss >> action;

        //             if (action == 'q') {
        //                 cout << "Game exited.\n";
        //                 break;
        //             }

        //             if (!(iss >> r >> c) || !inBounds(r, c)) {
        //                 cout << "Invalid input. Try again.\n";
        //                 Sleep(1000);
        //                 continue;
        //             }

        //             if (action == 'u') {
        //                 if (board[r][c].flagged) {
        //                     cout << "Cell is flagged. Unflag first.\n";
        //                     Sleep(1000);
        //                     continue;
        //                 }
        //                 if (board[r][c].hasMine) {
        //                     revealAllMines();
        //                     displayBoard(true);
        //                     cout << "*** BOOM! You hit a mine. Game Over. ***\n";
        //                     break;
        //                 }
        //                 if (!board[r][c].uncovered) {
        //                     cellsUncovered += uncoverRegion(r, c);
        //                 }
        //             } else if (action == 'f') {
        //                 if (!board[r][c].uncovered)
        //                     board[r][c].flagged = !board[r][c].flagged;
        //                 else {
        //                     cout << "Cannot flag an uncovered cell.\n";
        //                     Sleep(1000);
        //                 }
        //             } else {
        //                 cout << "Invalid action.\n";
        //                 Sleep(1000);
        //             }

        //             if (cellsUncovered == rows * cols - mineCount) {
        //                 revealAllMines();
        //                 displayBoard(true);
        //                 cout << "*** Congratulations! You Win! ***\n";
        //                 break;
        //             }
        //         }
        //     }
        // };

        // int main() {
        //     int rows, cols, mines;
        //     cout << "\n\nEnter number of rows: ";
        //     cin >> rows;
        //     cout << "Enter number of columns: ";
        //     cin >> cols;
        //     cout << "Enter number of mines: ";
        //     cin >> mines;

        //     if (rows <= 0 || cols <= 0 || mines <= 0 || mines >= rows * cols) {
        //         cout << "Invalid input. Try again.\n";
        //         return 1;
        //     }

        //     Minesweeper game(rows, cols, mines);
        //     game.run();
        //     return 0;
        // }





// 


#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

// ---------------- Song Node (Doubly Linked List) ----------------
struct SongNode {
    string song;
    SongNode* next = nullptr;
    SongNode* prev = nullptr;
};

// ---------------- BST Node for Sorted Songs ----------------
struct BSTNode {
    string song;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
};

// ---------------- Playlist Struct ----------------
struct Playlist {
    string name;
    SongNode* head = nullptr;
    SongNode* tail = nullptr;
    BSTNode* bstRoot = nullptr;
    SongNode* recentTop = nullptr;
    queue<string> playNextQueue;
    Playlist* next = nullptr;
};

Playlist* playlistsHead = nullptr;

SongNode* createSongNode(const string& songName) {
    SongNode* node = new SongNode;
    node->song = songName;
    return node;
}

void addSongToPlaylist(Playlist* pl, const string& songName) {
    SongNode* newNode = createSongNode(songName);
    newNode->prev = pl->tail;
    if (pl->tail)
        pl->tail->next = newNode;
    else
        pl->head = newNode;
    pl->tail = newNode;
}

void displayPlaylistSongs(Playlist* pl) {
    cout << "\n--- Songs in Playlist: " << pl->name << " ---\n";
    if (!pl->head) {
        cout << "No songs in this playlist.\n";
        return;
    }
    for (SongNode* curr = pl->head; curr; curr = curr->next) {
        cout << curr->song << endl;
    }
}

int countSongsInPlaylist(Playlist* pl) {
    int count = 0;
    for (SongNode* curr = pl->head; curr; curr = curr->next)
        count++;
    return count;
}

void deleteSongFromPlaylist(Playlist* pl, const string& songName) {
    SongNode* curr = pl->head;
    while (curr) {
        if (curr->song == songName) {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                pl->head = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;
            else
                pl->tail = curr->prev;

            delete curr;
            cout << "\nSong \"" << songName << "\" deleted from playlist.\n";
            return;
        }
        curr = curr->next;
    }
    cout << "\nSong not found in playlist.\n";
}

BSTNode* insertBST(BSTNode* root, const string& songName) {
    if (!root) {
        BSTNode* node = new BSTNode;
        node->song = songName;
        return node;
    }
    if (songName < root->song)
        root->left = insertBST(root->left, songName);
    else if (songName > root->song)
        root->right = insertBST(root->right, songName);
    return root;
}

void displaySortedSongs(BSTNode* root) {
    if (!root) return;
    displaySortedSongs(root->left);
    cout << root->song << endl;
    displaySortedSongs(root->right);
}

void pushRecentSong(Playlist* pl, const string& songName) {
    if (!pl->recentTop || pl->recentTop->song != songName) {
        SongNode* newNode = createSongNode(songName);
        newNode->next = pl->recentTop;
        pl->recentTop = newNode;
    }
}

void showRecentSongs(Playlist* pl) {
    if (!pl->recentTop) {
        cout << "\nNo recently played tracks.\n";
        return;
    }
    cout << "\n--- Recently Played (Playlist: " << pl->name << ") ---\n";
    for (SongNode* curr = pl->recentTop; curr; curr = curr->next)
        cout << curr->song << endl;
}

void showLastPlayedSong(Playlist* pl) {
    if (pl->recentTop)
        cout << "\nLast Played (Playlist: " << pl->name << "): " << pl->recentTop->song << endl;
    else
        cout << "\nNo song played yet in playlist.\n";
}

void enqueuePlayNext(Playlist* pl) {
    string song;
    cout << "\nEnter song name to enqueue for next play: ";
    getline(cin >> ws, song);
    pl->playNextQueue.push(song);
    cout << "Song added to play-next queue.\n";
}

void playFromQueue(Playlist* pl) {
    if (pl->playNextQueue.empty()) {
        cout << "\nPlay-next queue is empty.\n";
        return;
    }
    string song = pl->playNextQueue.front();
    pl->playNextQueue.pop();
    cout << "\nNow playing from queue: " << song << endl;
    pushRecentSong(pl, song);
}

void playSongFromPlaylist(Playlist* pl) {
    displayPlaylistSongs(pl);
    cout << "\nEnter song to play: ";
    string song;
    getline(cin >> ws, song);
    for (SongNode* curr = pl->head; curr; curr = curr->next) {
        if (curr->song == song) {
            cout << "\nNow playing: " << curr->song << endl;
            pushRecentSong(pl, curr->song);
            return;
        }
    }
    cout << "\nSong not found in playlist.\n";
}

Playlist* createPlaylist(const string& playlistName) {
    Playlist* pl = new Playlist;
    pl->name = playlistName;

    while (!pl->playNextQueue.empty())
        pl->playNextQueue.pop();

    if (!playlistsHead)
        playlistsHead = pl;
    else {
        Playlist* curr = playlistsHead;
        while (curr->next) curr = curr->next;
        curr->next = pl;
    }
    return pl;
}

Playlist* findPlaylist(const string& playlistName) {
    Playlist* curr = playlistsHead;
    while (curr) {
        if (curr->name == playlistName)
            return curr;
        curr = curr->next;
    }
    return nullptr;
}

void displayAllPlaylists() {
    cout << "\n--- All Playlists ---\n";
    if (!playlistsHead) {
        cout << "No playlists created yet.\n";
        return;
    }
    Playlist* curr = playlistsHead;
    while (curr) {
        cout << "\nPlaylist: " << curr->name << endl;
        displayPlaylistSongs(curr);
        curr = curr->next;
    }
}

int main() {
    cout << "\n--- Multi-Playlist Music Manager ---\n";
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Create New Playlist\n"
             << "2. Add Song to Playlist\n"
             << "3. Delete Song from Playlist\n"
             << "4. Display Songs in Playlist\n"
             << "5. Count Songs in Playlist\n"
             << "6. Play Song from Playlist\n"
             << "7. Show Recently Played Songs in Playlist\n"
             << "8. Show Last Played Song in Playlist\n"
             << "9. Enqueue Song to Play-Next Queue in Playlist\n"
             << "10. Play Song from Play-Next Queue in Playlist\n"
             << "11. Display Sorted Songs in Playlist\n"
             << "12. Display All Playlists\n"
             << "13. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter new playlist name: ";
            string name;
            getline(cin >> ws, name);
            if (findPlaylist(name)) {
                cout << "Playlist already exists!\n";
            } else {
                createPlaylist(name);
                cout << "Playlist \"" << name << "\" created.\n";
            }
        } else if (choice >= 2 && choice <= 11) {
            cout << "Enter playlist name: ";
            string plName;
            getline(cin >> ws, plName);
            Playlist* pl = findPlaylist(plName);
            if (!pl) {
                cout << "Playlist not found!\n";
                continue;
            }
            if (choice == 2) {
                cout << "Enter song name to add: ";
                string songName;
                getline(cin >> ws, songName);
                addSongToPlaylist(pl, songName);
                pl->bstRoot = insertBST(pl->bstRoot, songName);
                cout << "Song added to playlist.\n";
            } else if (choice == 3) {
                cout << "Enter song name to delete: ";
                string songName;
                getline(cin >> ws, songName);
                deleteSongFromPlaylist(pl, songName);
            } else if (choice == 4) {
                displayPlaylistSongs(pl);
            } else if (choice == 5) {
                cout << "Total songs in playlist: " << countSongsInPlaylist(pl) << endl;
            } else if (choice == 6) {
                playSongFromPlaylist(pl);
            } else if (choice == 7) {
                showRecentSongs(pl);
            } else if (choice == 8) {
                showLastPlayedSong(pl);
            } else if (choice == 9) {
                enqueuePlayNext(pl);
            } else if (choice == 10) {
                playFromQueue(pl);
            } else if (choice == 11) {
                cout << "\n--- Sorted Songs in Playlist \"" << pl->name << "\" ---\n";
                displaySortedSongs(pl->bstRoot);
            }
        } else if (choice == 12) {
            displayAllPlaylists();
        } else if (choice == 13) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 13);

    return 0;
}
