/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
	#define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
	public:
		virtual ~IMonitorDisplay();
    typedef enum e_data {
        PER_CENT,
        STRINGS,
        INTS,
        DOUBLE
    }           data;
	protected:
	private:
};

#endif /* !IMONITORDISPLAY_HPP_ */