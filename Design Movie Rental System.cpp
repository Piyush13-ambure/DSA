/*You have a movie renting company consisting of n shops. You want to implement a renting system that supports searching for, booking, and returning movies. The system should also support generating a report of the currently rented movies.

Each movie is given as a 2D integer array entries where entries[i] = [shopi, moviei, pricei] indicates that there is a copy of movie moviei at shop shopi with a rental price of pricei. Each shop carries at most one copy of a movie moviei.

The system should support the following functions:

Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. The shops should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopi should appear first. If there are less than 5 matching shops, then all of them should be returned. If no shop has an unrented copy, then an empty list should be returned.
Rent: Rents an unrented copy of a given movie from a given shop.
Drop: Drops off a previously rented copy of a given movie at a given shop.
Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from the shop shopj. The movies in res should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopj should appear first, and if there is still tie, the one with the smaller moviej should appear first. If there are fewer than 5 rented movies, then all of them should be returned. If no movies are currently being rented, then an empty list should be returned.
Implement the MovieRentingSystem class:

MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
List<Integer> search(int movie) Returns a list of shops that have an unrented copy of the given movie as described above.
void rent(int shop, int movie) Rents the given movie from the given shop.
void drop(int shop, int movie) Drops off a previously rented movie at the given shop.
List<List<Integer>> report() Returns a list of cheapest rented movies as described above.
Note: The test cases will be generated such that rent will only be called if the shop has an unrented copy of the movie, and drop will only be called if the shop had previously rented out the movie.*/


using int2=pair<int,int>;           // (price, shop)
using int3=tuple<int,int,int>;      // (price, shop, movie)

class MovieRentingSystem {
public:
    unordered_map<uint64_t,int> Shop;      // (shop,movie)->price
    unordered_map<int,set<int2>> Movie;    // movie->set(price,shop)
    set<int3> rented;                      // rented->set (price,shop,movie)

    static inline uint64_t key(int shop,int movie) {
        return (uint64_t)shop<<32|movie;
    }

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop=e[0], movie=e[1], price=e[2];
            Shop[key(shop,movie)]=price;
            Movie[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto& S=Movie[movie];
        int i=0;
        for (auto it=S.begin(); it!=S.end() && i<5; it++, i++) {
            ans.push_back(it->second); // shop
        }
        return ans;
    }

    void rent(int shop,int movie) {
        int price=Shop[key(shop,movie)];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop,int movie) {
        int price=Shop[key(shop,movie)];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for (auto it=rented.begin(); it!=rented.end() && i<5; it++, i++) {
            auto [price, shop, movie]=*it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};
