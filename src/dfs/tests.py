import pytest
from main import Graph 

def test_simple_graph():
    g = Graph()
    g.add_edge('A', 'B')
    g.add_edge('A', 'C')
    g.add_edge('B', 'D')
    
    result = g.dfs('A')
  
    assert set(result) == {'A', 'B', 'C', 'D'}
    assert result[0] == 'A'
    assert 'A' == result[0]
    assert 'C' in result[1:]
    assert 'B' in result[1:]
    assert result.index('D') > result.index('B')

def test_graph_with_disconnected_components():
    g = Graph()
    g.add_edge('A', 'B')
    g.add_edge('C', 'D')
    
    result = g.dfs('A')
    assert 'A' in result
    assert 'B' in result
    assert 'C' not in result
    assert 'D' not in result

def test_iteration_over_graph():
    g = Graph()
    g.add_edge('A', 'B')
    g.add_edge('A', 'C')
    g.add_edge('B', 'D')
    nodes_in_iteration = list(iter(g))

    assert set(nodes_in_iteration) == {'A', 'B', 'C', 'D'}
    assert nodes_in_iteration[0] == list(g.adj_list.keys())[0]

def test_cycle_graph():
    g = Graph()
    g.add_edge('A', 'B')
    g.add_edge('B', 'C')
    g.add_edge('C', 'A')
    
    result = g.dfs('A')
    assert set(result) == {'A', 'B', 'C'}
    assert result[0] == 'A'

def test_single_vertex():
    g = Graph()
    g.add_vertex('X')
    result = g.dfs('X')
    assert result == ['X']
