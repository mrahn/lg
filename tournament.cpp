// mirko.rahn@web.de

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
    sons[player] = 0;

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
    by_sons[sons.at (player)].push_back (player);
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
                  << ", " << sons.at (player)
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
