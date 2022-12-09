#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# define NUM_IDEAS	100

# include <string>

class	Brain {
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();

		Brain&		operator=(const Brain &brain);
		void		showIdeas() const;
		std::string	_ideas[NUM_IDEAS];
};

#endif