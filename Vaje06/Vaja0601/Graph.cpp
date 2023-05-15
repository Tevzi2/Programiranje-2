#include <Graph.hpp>

Graph::Graph(const std::string& title, const std::vector<int>& data)
    : title(title), data(data)
{
    ;
}

void Graph::setTitle(const std::string& title)
{
    this->title = title;
}

void Graph::setData(const std::vector<int>& data)
{
    this->data = data;
}

[[nodiscard]] std::string Graph::getTitle() const
{
    return title;
}

[[nodiscard]] std::vector<int> Graph::getData() const
{
    return data;
}

[[nodiscard]] int Graph::getMaxValue() const
{
    int current = data[0];

    if(data.size() == 0) return -1;

    for(uint32_t i = 1; i < data.size(); i++)
        if(current < data[i]) current = data[i];

    return current;
}

[[nodiscard]] int Graph::getMinValue() const
{
    int current = data[0];

    if(data.size() == 0) return -1;

    for(uint32_t i = 1; i < data.size(); i++)
        if(current > data[i]) current = data[i];

    return current;
}