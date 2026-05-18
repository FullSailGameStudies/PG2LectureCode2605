#pragma once
#include <vector>
#include <Card.h>
class Deck
{
public:
	const std::vector<Card>& Cards() const
	{
		return cards_;
	}
	void Cards(const std::vector<Card>& cards)
	{
		if (cards.size() == 52)
			cards_ = cards;
	}
private:
	std::vector<Card> cards_;
};

