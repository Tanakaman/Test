#pragma once

// 未実装.

namespace DEV
{
    /// <summary>
    /// シーンの遷移を行うクラスを表します.
    /// </summary>
    class SceneNavigator
    {
    public:
        static SceneNavigator& GetInstance()
        {
            static SceneNavigator Instance;
            return Instance;
        }

        /// <summary>
        /// 指定した名前のシーンへ遷移します.
        /// </summary>
        /// <param name="SceneName"></param>
        void Navigate(const TCHAR* SceneName);

    private:
        SceneNavigator();
        virtual ~SceneNavigator();
    };
};
