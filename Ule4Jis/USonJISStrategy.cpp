
#include "stdafx.h"
#include "USonJISStrategy.h"
#include "NormalKeyEmulation.h"
#include "PressAndReleaseDecorator.h"
#include "ShiftPressDecorator.h"
#include "ShiftReleaseDecorator.h"
#include "NopEmulation.h"

void USonJISStrategy::getEmulationMap(EmulationMapType *dest) {

	dest->clear();

	// @
	dest->insert(
		KeyCondition('2', true),
		new ShiftReleaseDecorator(
			std::auto_ptr<Emulation>(new NormalKeyEmulation(VK_OEM_3))
		)
	);
	// ^
	dest->insert(
		KeyCondition('6', true),
		new ShiftReleaseDecorator(
			std::auto_ptr<Emulation>(new NormalKeyEmulation(VK_OEM_7))
		)
	);
	// &
	dest->insert(KeyCondition('7', true), new NormalKeyEmulation('6'));
	// *
	dest->insert(KeyCondition('8', true), new NormalKeyEmulation(VK_OEM_1));
	// (
	dest->insert(KeyCondition('9', true), new NormalKeyEmulation('8'));
	// )
	dest->insert(KeyCondition('0', true), new NormalKeyEmulation('9'));
	// _
	dest->insert(KeyCondition(VK_OEM_MINUS, true),  new NormalKeyEmulation(VK_OEM_102));
	// =
	dest->insert(
		KeyCondition(VK_OEM_7),
		new ShiftPressDecorator(
			std::auto_ptr<Emulation>(new NormalKeyEmulation(VK_OEM_MINUS))
		)
	);
	// +
	dest->insert(KeyCondition(VK_OEM_7, true), new NormalKeyEmulation(VK_OEM_PLUS));

	// `
	dest->insert(KeyCondition(VK_OEM_AUTO), new NopEmulation());
	dest->insert(
		KeyCondition(VK_OEM_ENLW),
		new PressAndReleaseDecorator(
			std::auto_ptr<Emulation>(new ShiftPressDecorator(
					std::auto_ptr<Emulation>(new NormalKeyEmulation(VK_OEM_3))
				)
			)
		)
	);
	// ~
	dest->insert(KeyCondition(VK_OEM_AUTO, true), new NopEmulation());
	dest->insert(
		KeyCondition(VK_OEM_ENLW, true),
		new PressAndReleaseDecorator(
			std::auto_ptr<Emulation>(new NormalKeyEmulation(VK_OEM_7))
		)
	);

	// [
	dest->insert(KeyCondition(VK_OEM_3), new NormalKeyEmulation(VK_OEM_4));
	// ]
	dest->insert(KeyCondition(VK_OEM_4), new NormalKeyEmulation(VK_OEM_6));

	// {
	dest->insert(KeyCondition(VK_OEM_3, true), new NormalKeyEmulation(VK_OEM_4));
	// }
	dest->insert(KeyCondition(VK_OEM_4, true), new NormalKeyEmulation(VK_OEM_6));
	// :
	dest->insert(KeyCondition(VK_OEM_PLUS, true),
		new ShiftReleaseDecorator(std::auto_ptr<Emulation>(new NormalKeyEmulation(VK_OEM_1))));
	// '
	dest->insert(KeyCondition(VK_OEM_1),
		new ShiftPressDecorator(std::auto_ptr<Emulation>(new NormalKeyEmulation('7'))));
	// "
	dest->insert(KeyCondition(VK_OEM_1, true), new NormalKeyEmulation('2'));
	// '\'
	dest->insert(KeyCondition(VK_OEM_6), new NormalKeyEmulation(VK_OEM_102));
	// |
	dest->insert(KeyCondition(VK_OEM_6, true), new NormalKeyEmulation(VK_OEM_5));
}
