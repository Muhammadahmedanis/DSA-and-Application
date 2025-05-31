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















        #include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

// ---------------- Song Node (Doubly Linked List) ----------------
struct SongNode {
    char song[100];
    SongNode* next;
    SongNode* prev;
};

// ---------------- BST Node for Sorted Songs ----------------
struct BSTNode {
    char song[100];
    BSTNode* left;
    BSTNode* right;
};

// ---------------- Playlist Struct ----------------
struct Playlist {
    char name[100];
    SongNode* head;
    SongNode* tail;
    BSTNode* bstRoot;
    SongNode* recentTop;
    queue<string> playNextQueue;
    Playlist* next;
};

Playlist* playlistsHead = nullptr;

SongNode* createSongNode(const char* songName) {
    SongNode* node = new SongNode;
    strcpy(node->song, songName);
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

void addSongToPlaylist(Playlist* pl, const char* songName) {
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

void deleteSongFromPlaylist(Playlist* pl, const char* songName) {
    SongNode* curr = pl->head;
    while (curr) {
        if (strcmp(curr->song, songName) == 0) {
            if (curr->prev) curr->prev->next = curr->next;
            else pl->head = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            else pl->tail = curr->prev;
            delete curr;
            cout << "\nSong \"" << songName << "\" deleted from playlist.\n";
            return;
        }
        curr = curr->next;
    }
    cout << "\nSong not found in playlist.\n";
}

BSTNode* insertBST(BSTNode* root, const char* songName) {
    if (!root) {
        BSTNode* node = new BSTNode;
        strcpy(node->song, songName);
        node->left = node->right = nullptr;
        return node;
    }
    if (strcmp(songName, root->song) < 0)
        root->left = insertBST(root->left, songName);
    else if (strcmp(songName, root->song) > 0)
        root->right = insertBST(root->right, songName);
    return root;
}

void displaySortedSongs(BSTNode* root) {
    if (!root) return;
    displaySortedSongs(root->left);
    cout << root->song << endl;
    displaySortedSongs(root->right);
}

void pushRecentSong(Playlist* pl, const char* songName) {
    if (!pl->recentTop || strcmp(pl->recentTop->song, songName) != 0) {
        SongNode* newNode = createSongNode(songName);
        newNode->next = pl->recentTop;
        newNode->prev = nullptr;
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
    cin >> ws;
    getline(cin, song);
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
    pushRecentSong(pl, song.c_str());
}

void playSongFromPlaylist(Playlist* pl) {
    displayPlaylistSongs(pl);
    cout << "\nEnter song to play: ";
    char song[100];
    cin >> ws;
    cin.getline(song, 100);
    SongNode* curr = pl->head;
    while (curr) {
        if (strcmp(curr->song, song) == 0) {
            cout << "\nNow playing: " << curr->song << endl;
            pushRecentSong(pl, curr->song);
            return;
        }
        curr = curr->next;
    }
    cout << "\nSong not found in playlist.\n";
}

Playlist* createPlaylist(const char* playlistName) {
    Playlist* pl = new Playlist;
    strcpy(pl->name, playlistName);
    pl->head = pl->tail = nullptr;
    pl->bstRoot = nullptr;
    pl->recentTop = nullptr;
    while (!pl->playNextQueue.empty()) pl->playNextQueue.pop();
    pl->next = nullptr;

    if (!playlistsHead) {
        playlistsHead = pl;
    } else {
        Playlist* curr = playlistsHead;
        while (curr->next) curr = curr->next;
        curr->next = pl;
    }
    return pl;
}

Playlist* findPlaylist(const char* playlistName) {
    Playlist* curr = playlistsHead;
    while (curr) {
        if (strcmp(curr->name, playlistName) == 0)
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
            char name[100];
            cin >> ws;
            cin.getline(name, 100);
            if (findPlaylist(name)) {
                cout << "Playlist already exists!\n";
            } else {
                createPlaylist(name);
                cout << "Playlist \"" << name << "\" created.\n";
            }
        } else if (choice >= 2 && choice <= 11) {
            cout << "Enter playlist name: ";
            char plName[100];
            cin >> ws;
            cin.getline(plName, 100);
            Playlist* pl = findPlaylist(plName);
            if (!pl) {
                cout << "Playlist not found!\n";
                continue;
            }
            if (choice == 2) {
                cout << "Enter song name to add: ";
                char songName[100];
                cin >> ws;
                cin.getline(songName, 100);
                addSongToPlaylist(pl, songName);
                pl->bstRoot = insertBST(pl->bstRoot, songName);
                cout << "Song added to playlist.\n";
            } else if (choice == 3) {
                cout << "Enter song name to delete: ";
                char songName[100];
                cin >> ws;
                cin.getline(songName, 100);
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






















#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // Adjacency list: (neighbor, weight)
    vector<Edge> edges;

    // Union-Find helpers
    vector<int> parent;

    int findParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionSets(int u, int v) {
        parent[findParent(u)] = findParent(v);
    }

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    void primMST() {
        vector<bool> visited(V, false);
        vector<int> key(V, 1e9), parent(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        key[0] = 0;
        pq.push({0, 0});
        int totalCost = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;
            totalCost += key[u];

            for (const auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                if (!visited[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({w, v});
                }
            }
        }

        cout << "\nPrim's MST:\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i << " : " << key[i] << "\n";
        cout << "Total cost: " << totalCost << "\n";
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(), compare);
        parent.resize(V);
        for (int i = 0; i < V; i++) parent[i] = i;

        int totalCost = 0;
        cout << "\nKruskal's MST:\n";
        for (const auto &e : edges) {
            if (findParent(e.u) != findParent(e.v)) {
                unionSets(e.u, e.v);
                cout << e.u << " - " << e.v << " : " << e.w << "\n";
                totalCost += e.w;
            }
        }
        cout << "Total cost: " << totalCost << "\n";
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.primMST();
    g.kruskalMST();

    return 0;
}