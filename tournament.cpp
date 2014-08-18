// mirko.rahn@web.de

// Usage:
// > ls
// CMakeLists.txt  tournament.cpp
// > mkdir build && cd build
// build> CC=clang CXX=clang++ cmake .. -DHTMLCXX_PREFIX=$HOME && make
// [...]
// build> for ((i = 1; i < 12; ++i)); do wget http://www.littlegolem.net/jsp/tournament/tournament.jsp?trnid=havannah.ch.${i}.1.1 -O /dev/stdout -o /dev/null; done | ./tournament
// #PLAYERS 31
// #GAMES 442
// #MOVES 23686
// #DRAWS 0
// * * * BY POINTS
// [  1] Mirko Rahn (108/77, 3968, 1.4026)
// [  2] fritzd (92/59, 3660, 1.55932)
// [  3] Jos Dekker ★ (74/51, 2844, 1.45098)
// [  4] Sol ★ (68/59, 2164, 1.15254)
// [  5] Tony (62/35, 2808, 1.77143)
// [  6] cutecat (56/52, 2120, 1.07692)
// [  7] bennok (56/58, 2112, 0.965517)
// [  8] christian freeling ★ (56/59, 1844, 0.949153)
// [  9] Maciej Celuch (38/26, 1376, 1.46154)
// [ 10] Marius Halsor ★ (36/52, 1236, 0.692308)
// [ 11] halladba (26/35, 1204, 0.742857)
// [ 12] Pascal Huybers (24/33, 624, 0.727273)
// [ 13] Thomas Reinhardt (22/18, 656, 1.22222)
// [ 14] Jonathan (22/35, 988, 0.628571)
// [ 15] 5466 (20/32, 748, 0.625)
// [ 16] Kieran O'Donnell ★ (18/17, 528, 1.05882)
// [ 17] eobllor (16/8, 884, 2)
// [ 18] Bernhard Herwig (16/16, 404, 1)
// [ 19] Ray Garrison ★ (14/16, 564, 0.875)
// [ 20] Peter Koning (12/17, 328, 0.705882)
// [ 21] z (12/27, 524, 0.444444)
// [ 22] Strange Yeah (10/10, 304, 1)
// [ 23] Przemek Drochomirecki (10/25, 192, 0.4)
// [ 24] Ed Collins (6/8, 132, 0.75)
// [ 25] Orbilin (4/8, 156, 0.5)
// [ 26] Castro_bot (4/9, 116, 0.444444)
// [ 27] ypercube (2/9, 0, 0.222222)
// [ 28] mickgraham (0/8, 0, 0), fallinsky (0/8, 0, 0), mirror_man2 (0/8, 0, 0)
// [ 31] Lukasz Lew (0/9, 0, 0)
// * * * BY RATIO
// [  1] eobllor (16/8, 884, 2)
// [  2] Tony (62/35, 2808, 1.77143)
// [  3] fritzd (92/59, 3660, 1.55932)
// [  4] Maciej Celuch (38/26, 1376, 1.46154)
// [  5] Jos Dekker ★ (74/51, 2844, 1.45098)
// [  6] Mirko Rahn (108/77, 3968, 1.4026)
// [  7] Thomas Reinhardt (22/18, 656, 1.22222)
// [  8] Sol ★ (68/59, 2164, 1.15254)
// [  9] cutecat (56/52, 2120, 1.07692)
// [ 10] Kieran O'Donnell ★ (18/17, 528, 1.05882)
// [ 11] Bernhard Herwig (16/16, 404, 1), Strange Yeah (10/10, 304, 1)
// [ 13] bennok (56/58, 2112, 0.965517)
// [ 14] christian freeling ★ (56/59, 1844, 0.949153)
// [ 15] Ray Garrison ★ (14/16, 564, 0.875)
// [ 16] Ed Collins (6/8, 132, 0.75)
// [ 17] halladba (26/35, 1204, 0.742857)
// [ 18] Pascal Huybers (24/33, 624, 0.727273)
// [ 19] Peter Koning (12/17, 328, 0.705882)
// [ 20] Marius Halsor ★ (36/52, 1236, 0.692308)
// [ 21] Jonathan (22/35, 988, 0.628571)
// [ 22] 5466 (20/32, 748, 0.625)
// [ 23] Orbilin (4/8, 156, 0.5)
// [ 24] Castro_bot (4/9, 116, 0.444444), z (12/27, 524, 0.444444)
// [ 26] Przemek Drochomirecki (10/25, 192, 0.4)
// [ 27] ypercube (2/9, 0, 0.222222)
// [ 28] mickgraham (0/8, 0, 0), fallinsky (0/8, 0, 0), mirror_man2 (0/8, 0, 0), Lukasz Lew (0/9, 0, 0)
// * * * BY SON
// [  1] Mirko Rahn (108/77, 3968, 1.4026)
// [  2] fritzd (92/59, 3660, 1.55932)
// [  3] Jos Dekker ★ (74/51, 2844, 1.45098)
// [  4] Tony (62/35, 2808, 1.77143)
// [  5] Sol ★ (68/59, 2164, 1.15254)
// [  6] cutecat (56/52, 2120, 1.07692)
// [  7] bennok (56/58, 2112, 0.965517)
// [  8] christian freeling ★ (56/59, 1844, 0.949153)
// [  9] Maciej Celuch (38/26, 1376, 1.46154)
// [ 10] Marius Halsor ★ (36/52, 1236, 0.692308)
// [ 11] halladba (26/35, 1204, 0.742857)
// [ 12] Jonathan (22/35, 988, 0.628571)
// [ 13] eobllor (16/8, 884, 2)
// [ 14] 5466 (20/32, 748, 0.625)
// [ 15] Thomas Reinhardt (22/18, 656, 1.22222)
// [ 16] Pascal Huybers (24/33, 624, 0.727273)
// [ 17] Ray Garrison ★ (14/16, 564, 0.875)
// [ 18] Kieran O'Donnell ★ (18/17, 528, 1.05882)
// [ 19] z (12/27, 524, 0.444444)
// [ 20] Bernhard Herwig (16/16, 404, 1)
// [ 21] Peter Koning (12/17, 328, 0.705882)
// [ 22] Strange Yeah (10/10, 304, 1)
// [ 23] Przemek Drochomirecki (10/25, 192, 0.4)
// [ 24] Orbilin (4/8, 156, 0.5)
// [ 25] Ed Collins (6/8, 132, 0.75)
// [ 26] Castro_bot (4/9, 116, 0.444444)
// [ 27] mickgraham (0/8, 0, 0), fallinsky (0/8, 0, 0), mirror_man2 (0/8, 0, 0), ypercube (2/9, 0, 0.222222), Lukasz Lew (0/9, 0, 0)

#include <htmlcxx/html/ParserDom.h>

#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace
{
  std::string read_stdin()
  {
    std::cin >> std::noskipws;

    return std::string ( std::istream_iterator<char> (std::cin)
                       , std::istream_iterator<char>()
                       );
  }

  std::string content_of_next_cell
    ( tree<htmlcxx::HTML::Node>::iterator& node
    , tree<htmlcxx::HTML::Node>::iterator const end
    )
  {
    while (node != end && node->tagName() != "td")
    {
      ++node;
    }

    if (node != end)
    {
      ++node;
    }

    return (node != end) ? (node->text())
      : throw std::runtime_error ("could not find table cell");
  }

  std::pair<int, int> parse_result (std::string const& result)
  {
    std::size_t pos (0);
    int const l (std::stoi (result, &pos));
    int const r (std::stoi (result.substr (pos + 3)));

    return {l, r};
  }

  double ratio (double numerator, double denominator)
  {
    return numerator / denominator;
  }

  template<typename T>
  void print_table
    ( std::string const& header
    , T const& table
    , std::function<void (std::list<std::string> const&)> const& print_elem
    )
  {
    int i (1);

    std::cout << "* * * " << header << std::endl;

    for (auto const& elem : table)
    {
      std::cout << "[" << std::setw (3) << i << "] ";

      print_elem (elem.second);

      std::cout << std::endl;

      i += elem.second.size();
    }
  }
}

int main()
try
{
  tree<htmlcxx::HTML::Node> const dom
    (htmlcxx::HTML::ParserDom().parseTree (read_stdin()));
  tree<htmlcxx::HTML::Node>::iterator node (dom.begin());

  std::unordered_map<std::string, int> games;
  std::unordered_map<std::string, int> points;
  std::unordered_map<std::string, std::list<std::string>> won;
  std::unordered_map<std::string, std::list<std::string>> drawn;
  std::unordered_set<std::string> players;

  int num_games (0);
  int num_draws (0);
  int num_moves (0);

  while (node != dom.end())
  {
    if (node->text().size() && *(node->text().begin()) == '#')
    {
      // std::string const game_id (node->text());
      std::string const player1 (content_of_next_cell (node, dom.end()));
      std::string const player2 (content_of_next_cell (node, dom.end()));
      std::pair<int, int> const result
        (parse_result (content_of_next_cell (node, dom.end())));
      std::string const moves (content_of_next_cell (node, dom.end()));

      num_games += 1;
      num_moves += std::stoi (moves);
      players.insert (player1);
      players.insert (player2);
      games[player1] += 1;
      games[player2] += 1;
      points[player1] += result.first;
      points[player2] += result.second;

      if (result.first > result.second)
      {
        won[player1].push_back (player2);
      }
      else if (result.first < result.second)
      {
        won[player2].push_back (player1);
      }
      else
      {
        drawn[player1].push_back (player2);
        drawn[player2].push_back (player1);
        num_draws += 1;
      }
    }

    ++node;
  }

  std::cout << "#PLAYERS " << players.size() << std::endl;
  std::cout << "#GAMES " << num_games << std::endl;
  std::cout << "#MOVES " << num_moves << std::endl;
  std::cout << "#DRAWS " << num_draws << std::endl;

  std::unordered_map<std::string, int> sons;

  for (std::string const& player : players)
  {
    for (std::string const& other : won[player])
    {
      sons[player] += 2 * points.at (other);
    }
    for (std::string const& other : drawn[player])
    {
      sons[player] += points.at (other);
    }
  }

  struct compare_points
  {
    bool operator() ( std::pair<int, int> const& l
                    , std::pair<int, int> const& r
                    ) const
    {
      return l.first > r.first
        || (l.first == r.first && l.second < r.second);
    }
  };

  std::map<std::pair<int, int>, std::list<std::string>, compare_points>
    by_points;
  std::map<double, std::list<std::string>, std::greater<double>> by_ratios;
  std::map<int, std::list<std::string>, std::greater<int>> by_sons;

  for (std::string const& player : players)
  {
    by_points[{points.at (player), games.at (player)}].push_back (player);
    by_ratios[ratio (points.at (player), games.at (player))]
      .push_back (player);
    by_sons[sons[player]].push_back (player);
  }

  auto const print_players
    ([&points, &games, &sons] (std::list<std::string> const& ps)
    {
      bool first (true);

      for (std::string const& player : ps)
      {
        std::cout << (first ? "" : ", ")
                  << player
                  << " (" << points.at (player)
                  << "/" << games.at (player)
                  << ", " << sons[player]
                  << ", " << ratio (points.at (player), games.at (player))
                  << ")";

        first = false;
      }
    }
    );

  print_table ("BY POINTS", by_points, print_players);
  print_table ("BY RATIO", by_ratios, print_players);
  print_table ("BY SON", by_sons, print_players);

  return 0;
}
catch (std::exception const& ex)
{
  std::cerr << "EXCEPTION: " << ex.what() << std::endl;

  return -1;
}
