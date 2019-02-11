/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
	#define WARPSYSTEM_HPP_

namespace WarpSystem {
	class QuantumReactor {
		public:
			QuantumReactor();
			void setStability(bool val);
		bool _stability;
	};
	class Core {
		public:
			Core(QuantumReactor *coreReactor);
			QuantumReactor *checkReactor();
		private:
			QuantumReactor *_coreReactor;
	};
};

#endif /* !WARPSYSTEM_HPP_ */
