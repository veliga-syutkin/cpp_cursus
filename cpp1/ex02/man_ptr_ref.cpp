/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_ptr_ref.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:50:09 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/04 17:54:39 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::cout << " \n\
Once there was a small kingdom, ruled by 5 brothers.  \n\
Each important decision was voted by all of them.  \n\
But not every time they could reunite;  \n\
And in order to make a decision,  \n\
One could give his vote to an representative. \n\
 \n\
At one point, they decided to make a vote about the color of the castle. \n\
For the such (un)important decision, only 2 of them were present, \n\
While there were 2 other people representing the missing 3 brothers. \n\
One was REF, the other was PTR. \n\
The REF represented only the 3rd brother. [REF acts like an alias] \n\
The PTR represented the 4th and then the 5th. [PTR is reassignable] \n\
Once all votes submitted and counted,  \n\
The REF came back to represented 3rd brother and told him the results. [how REF works] \n\
The PTR, however, was lost because he didn't know who he was representing anymore. [NULL aka nullptr] \n\
This is why, in the kingdom of programming, the REF is trusted for its loyalty, while the PTR, though versatile, must be handled with care to avoid confusion or chaos. \n\
" << std::endl;
}