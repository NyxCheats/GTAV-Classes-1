#pragma once

#define UI_LANDING_PAGE_ONLY(...)

namespace rage {
	enum LoadingScreenMovieContext {
		LOADINGSCREEN_SCALEFORM_CTX_BLANK, // Blank Screen ( default value in the scaleform movie)
		LOADINGSCREEN_SCALEFORM_CTX_LEGAL, // Legal Screen ( With the spinner icons and descriptions )
		LOADINGSCREEN_SCALEFORM_CTX_INSTALL, // Installer Screen ( Uses a progress bar )
		LOADINGSCREEN_SCALEFORM_CTX_GAMELOAD, // Game loading screen ( Uses a progress bar )
		LOADINGSCREEN_SCALEFORM_CTX_GAMELOAD_NEWS, // Game loading (with network connectivity to retrieve rockstar news stories)
		UI_LANDING_PAGE_ONLY(LOADINGSCREEN_SCALEFORM_CTX_LANDING) // PC & Gen9 Landing Context (with network connectivity to retrieve rockstar news stories, but does not cycle backgrounds automatically)
	};
}