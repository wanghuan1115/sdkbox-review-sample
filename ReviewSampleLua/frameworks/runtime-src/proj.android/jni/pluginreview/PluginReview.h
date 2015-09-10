/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/

#ifndef _PLUGIN_AGECHEQ_H_
#define _PLUGIN_AGECHEQ_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox
{
    class ReviewListener
    {
    public:

        /**
         * trigger when alert prompt show
         */
        virtual void didDisplayAlert() = 0;

        /**
         * trigger when user refuse to rate
         */
        virtual void didDeclineToRate() = 0;

        /**
         * trigger when user want to rate
         */
        virtual void didToRate() = 0;

        /**
         * trigger when user want to remind later
         */
        virtual void didToRemindLater() = 0;
    };

    class PluginReview
    {
    public:

        /**
         *  initialize the plugin instance.
         */
        static bool init();

        /**
         * Set listener to listen for adcolony events
         */
        static void setListener(ReviewListener* listener);

        /**
         * Get the listener
         */
        static ReviewListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();


        /*
         Tells Appirater to try and show the prompt (a rating alert). The prompt will be showed
         if there is connection available, the user hasn't declined to rate
         or hasn't rated current version.

         You could call to show the prompt regardless Appirater settings,
         e.g., in case of some special event in your app.
         */
        static void tryToShowPrompt();

        /*
         Tells Appirater to show the prompt (a rating alert).
         Similar to tryToShowPrompt, but without checks (the prompt is always displayed).
         Passing false will hide the rate later button on the prompt.

         The only case where you should call this is if your app has an
         explicit "Rate this app" command somewhere. This is similar to rateApp,
         but instead of jumping to the review directly, an intermediary prompt is displayed.
         */
        static void forceToShowPrompt(bool displayRateLaterButton = true);

        /*
         Tells Appirater that the user performed a significant event. A significant
         event is whatever you want it to be. If you're app is used to make VoIP
         calls, then you might want to call this method whenever the user places
         a call. If it's a game, you might want to call this whenever the user
         beats a level boss.

         If the user has performed enough significant events and used the app enough,
         you can suppress the rating alert by passing NO for canPromptForRating. The
         rating alert will simply be postponed until it is called again with YES for
         canPromptForRating. The rating alert can also be triggered by appLaunched:
         and appEnteredForeground: (as long as you pass YES for canPromptForRating
         in those methods).
         */
        static void userDidSignificantEvent(bool canPromptForRating);

        /*
         * Set customized title for alert view.
         */
        static void setCustomPromptTitle(const std::string& title);

        /*
         * Set customized message for alert view.
         */
        static void setCustomPromptMessage(const std::string& message);

        /*
         * Set customized cancel button title for alert view.
         */
        static void setCustomPromptCancelButtonTitle(const std::string& cancelTitle);

        /*
         * Set customized rate button title for alert view.
         */
        static void setCustomPromptRateButtonTitle(const std::string& rateTitle);

        /*
         * Set customized rate later button title for alert view.
         */
        static void setCustomPromptRateLaterButtonTitle(const std::string& rateLaterTitle);

    };
}

#endif
