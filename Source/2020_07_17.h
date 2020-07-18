struct Void {};
struct Integer{};
struct Real{};
struct Boolean{};
struct Text{};
struct Vec2{Real X; Real Y;};
struct Vec3{Real X; Real Y; Real Z;};
struct Int2{Integer X; Integer Y;};
struct Int3{Integer X; Integer Y; Integer Z;};
struct Ident{};

template <typename ElemType>
struct Array {
	ElemType operator[](Integer Index);
	ElemType operator[](Ident Id);
	ElemType operator[](CNod Object);
	Integer count;
	Array<ElemType> sort();
	Array<ElemType> sortreverse();
	Void add(ElemType Elem);
	Void addfirst(ElemType Elem);
	Boolean remove(ElemType Elem);
	Boolean exists(ElemType Elem);
	Integer keyof(ElemType Elem);
	Void clear();
	Boolean containsonly(Array<ElemType> Elem);
	Boolean containsoneof(Array<ElemType> Elem);
	Array<ElemType> slice(Integer Index);
	Array<ElemType> slice(Integer Index, Integer Count);
};

template <typename KeyType, typename ElemType>
struct AssociativeArray {
	ElemType operator[](KeyType Key);
	ElemType get(KeyType Key);
	ElemType get(KeyType Key, ElemType DefaultValue);
	Integer count();
	AssociativeArray<KeyType, ElemType> sort();
	AssociativeArray<KeyType, ElemType> sortreverse();
	AssociativeArray<KeyType, ElemType> sortkey();
	AssociativeArray<KeyType, ElemType> sortkeyreverse();
	Boolean remove(ElemType Elem);
	Boolean removekey(KeyType Key);
	Boolean exists(ElemType Elem);
	Boolean existskey(KeyType Key);
	KeyType keyof(ElemType Elem);
	Void clear();
	Boolean containsonly(Array<ElemType> Elem);
	Boolean containsoneof(Array<ElemType> Elem);
};

/*!
* \brief This is the base Manialink page interface.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMlScript : public CNod {
public :
	/*!
	
	*/
	enum LinkType {
		ExternalBrowser,
		ManialinkBrowser,
		Goto,
		ExternalFromId,
		ManialinkFromId,
		GotoFromId,
	};
/*!

*/
	const	CMlPage Page;
/*!

*/
	const	Boolean PageIsVisible;
/*!

*/
			Boolean PageAlwaysUpdateScript;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Period;
/*!

*/
	const	Integer CurrentTime;
/*!
Local user structure.
*/
	const	CUser LocalUser;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	Array<CMlScriptEvent> PendingEvents;
/*!

*/
			Void Dbg_SetProcessed(CMlScriptEvent Event);
/*!

*/
			Boolean Dbg_WarnOnDroppedEvents;
/*!

*/
	const	Real MouseX;
/*!

*/
	const	Real MouseY;
/*!

*/
	const	Boolean MouseLeftButton;
/*!

*/
	const	Boolean MouseRightButton;
/*!

*/
	const	Boolean MouseMiddleButton;
/*!

*/
	const	Boolean KeyUp;
/*!

*/
	const	Boolean KeyDown;
/*!

*/
	const	Boolean KeyLeft;
/*!

*/
	const	Boolean KeyRight;
/*!

*/
	const	Boolean KeyReturn;
/*!

*/
	const	Boolean KeySpace;
/*!

*/
	const	Boolean KeyDelete;
/*!

*/
			Boolean IsKeyPressed(Integer KeyCode);
/*!

*/
			Boolean EnableMenuNavigationInputs;
/*!

*/
			Void EnableMenuNavigation(Boolean EnableInputs,Boolean WithAutoFocus,CMlControl AutoBackControl,Integer InputPriority);
/*!

*/
			Void EnableMenuNavigation(Boolean EnableInputs,Boolean WithAutoFocus,Boolean WithManualScroll,CMlControl AutoBackControl,Integer InputPriority);
/*!

*/
	const	Boolean IsMenuNavigationForeground;
/*!

*/
			Void OpenLink(Text Url,CMlScript::LinkType LinkType);
/*!

*/
			Void TriggerPageAction(Text ActionString);
/*!

*/
	const	CParsingManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!

*/
	const	CVideoManager Video;
/*!

*/
	const	CAudioManager Audio;
/*!

*/
	const	CInputManager Input;
/*!

*/
	const	CDataFileMgr DataFileMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CRankingsZoneMgr ZoneMgr;
/*!

*/
	const	CUserV2Manager UserMgr;
/*!

*/
	const	CAnimManager AnimMgr;
/*!

*/
	const	CMenuSceneManager MenuSceneMgr;
/*!

*/
	const	CSystemPlatform System;
/*!
Send a custom event to the owner of the layer.
*/
			Void SendCustomEvent(Text Type,Array<Text> Data);
/*!

*/
			Void PreloadImage(Text ImageUrl);
/*!

*/
			Void PreloadAll();
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
};

/*!
* \brief API for Maniaplanet client scripts.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaApp : public CNod {
public :
	/*!
	
	*/
	enum ELinkType {
		ExternalBrowser,
		ManialinkBrowser,
	};
/*!

*/
	const	Text ManiaAppUrl;
/*!

*/
	const	Text ManiaAppBaseUrl;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Boolean IsVisible;
/*!

*/
			Integer LayersDefaultManialinkVersion;
/*!

*/
	const	CUser LocalUser;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
			Boolean EnableMenuNavigationInputs;
/*!

*/
	const	Array<CUILayer> UILayers;
/*!

*/
			CUILayer UILayerCreate();
/*!

*/
			Void UILayerDestroy(CUILayer Layer);
/*!

*/
			Void UILayerDestroyAll();
/*!

*/
			Void LayerCustomEvent(CUILayer Layer,Text Type,Array<Text> Data);
/*!

*/
			Void OpenLink(Text Url,CManiaApp::ELinkType LinkType);
/*!
Explore to given file or folder. Returns False if it does not exist on the filesystem. (may be because it is in a pack)
*/
			Boolean OpenFileInExplorer(Text FileName);
/*!

*/
			Void Dialog_Message(Text Message);
/*!

*/
	const	CParsingManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!

*/
	const	CVideoManager Video;
/*!

*/
	const	CAudioManager Audio;
/*!

*/
	const	CInputManager Input;
/*!

*/
	const	CDataFileMgr DataFileMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CRankingsZoneMgr ZoneMgr;
/*!

*/
	const	CTrackingMgr TrackingMgr;
/*!

*/
	const	CUserV2Manager UserMgr;
/*!

*/
	const	CSystemPlatform System;
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
};

/*!
* \brief API for editor plugins.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CEditorMainPlugin : public CAnyEditorPlugin {
public :
	/*!
	
	*/
	enum EMeshEditorAPI {
		Materials,
		Interactions,
		Display,
		Global,
		Sets,
		Voxel,
		PickInfo,
		UndoRedo,
	};
/*!

*/
			Void Help_Open();
/*!

*/
			Void Help_Close();
/*!

*/
			CEditorPluginHandle GetPluginHandle(Text Name);
/*!

*/
			Void SendPluginEvent(CEditorPluginHandle Handle,Text Type,Array<Text> Data);
/*!

*/
			Void Context_SetActive(Text ContextName,Boolean IsActive);
/*!

*/
			Boolean Context_IsActive(Text ContextName);
/*!

*/
			Boolean Binding_IsActive(Text BindingName);
/*!

*/
			Boolean Binding_IsActive(Text ContextName,Text BindingName);
/*!

*/
			Void Plugin_SetClearance(CEditorPluginHandle Handle,CEditorMainPlugin::EMeshEditorAPI API,Boolean IsAllowed);
/*!

*/
	const	Array<CEditorPluginHandle> Plugins;
};

/*!
* \brief Server plugin
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CServerPlugin : public CNod {
public :
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	CMapInfo MapInfo;
/*!

*/
			CClient GetClient(Text Login);
/*!

*/
			CClient GetClient(CUIConfig UI);
/*!

*/
			CClient GetClient(CUser Login);
/*!

*/
			CClient GetClientFromWebServicesUserId(Text WebServicesUserId);
/*!
Currently connected Users.
*/
	const	Array<CClient> Clients;
/*!
Users connected as spectators.
*/
	const	Array<CClient> Spectators;
/*!
Users connected as players.
*/
	const	Array<CClient> Players;
/*!
Sorted scores.
*/
	const	Array<CScore> Scores;
/*!

*/
	const	Array<CUser> Users;
/*!

*/
	const	Array<CTeam> Teams;
/*!

*/
			Text NeutralEmblemUrl;
/*!

*/
			Text ForcedClubLinkUrl1;
/*!

*/
			Text ForcedClubLinkUrl2;
/*!

*/
			Void TweakTeamColorsToAvoidHueOverlap();
/*!

*/
	const	Array<Integer> ClansNbPlayers;
/*!

*/
	const	Array<Integer> ClanScores;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Array<CServerPluginEvent> PendingEvents;
/*!

*/
			Void TriggerModeScriptEvent(Text Type,Array<Text> Data);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Boolean BoolVal);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Integer IntVal);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Real RealVal);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Text TextVal);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Vec2 Vec2Val);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Vec3 Vec3Val);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Int2 Int2Val);
/*!

*/
			Void SendModeScriptCommand(Text CommandName,Int3 Int3Val);
/*!

*/
	const	Boolean MapLoaded;
/*!

*/
	const	Boolean MapUnloadRequested;
/*!

*/
	const	Array<CMapInfo> MapList;
/*!

*/
	const	Integer CurMapIndex;
/*!

*/
			Integer NextMapIndex;
/*!

*/
			Void RestartMap();
/*!

*/
			Void NextMap();
/*!

*/
			Boolean HoldMapUnloadRequest;
/*!
Enable minimap on the clients, even if the mode does not do it.
*/
			Boolean Client_ComputeMinimap;
/*!

*/
	const	CUIConfigMgr UIManager;
/*!

*/
	const	CServerAdmin ServerAdmin;
/*!

*/
	const	CXmlRpc XmlRpc;
/*!

*/
	const	CParsingManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!

*/
	const	CSystemPlatform System;
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
};

/*!
* \brief Rules API for ShootMania gamemodes.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CSmMode : public CMode {
public :
	/*!
	
	*/
	enum ESmScoreSortOrder {
		TotalPoints,
		RoundPoints,
		EliminationsInflicted,
		EliminationsTaken,
		Respawns,
		DamageInflicted,
		DamageTaken,
		BestRace,
		BestLap,
		PrevRace,
		Name,
		LadderRank,
	};
	/*!
	
	*/
	enum EWeapon {
		Laser,
		Nucleus,
		Arrow,
		Rocket,
		Missile,
	};
	/*!
	
	*/
	enum EActionSlot {
		Slot_A,
		Slot_B,
		Slot_C,
		Slot_D,
		Slot_E,
		Slot_F,
		Slot_G,
		Slot_H,
	};
	/*!
	
	*/
	enum EActionInput {
		Weapon,
		Secondary,
		Movement,
		Activable1,
		Activable2,
		Activable3,
		Activable4,
		Activable5,
		Activable6,
		Activable7,
		Activable8,
		Activable9,
		Activable0,
		Consumable1,
		Consumable2,
		None,
	};
	/*!
	
	*/
	enum EGameplay {
		Default,
		Mp3Beta0,
	};
	/*!
	
	*/
	enum ERespawnBehaviour {
		Custom,
		DoNothing,
		GiveUpBeforeFirstCheckpoint,
		AlwaysGiveUp,
		AlwaysRespawn,
	};
	/*!
	
	*/
	enum ECheckpointBehaviour {
		Custom,
		Default,
		InfiniteLaps,
	};
	/*!
	
	*/
	enum EGiveUpBehaviour {
		Custom,
		DoNothing,
		GiveUp,
	};
/*!

*/
			Integer StartTime;
/*!

*/
			Integer EndTime;
/*!

*/
			Integer SpawnInvulnerabilityDuration;
/*!

*/
			Integer UnspawnAnimDuration;
/*!

*/
			Integer SpawnDelayDuration;
/*!

*/
			CSmMode::ERespawnBehaviour RespawnBehaviour;
/*!

*/
			CSmMode::ECheckpointBehaviour CheckpointBehaviour;
/*!

*/
			CSmMode::EGiveUpBehaviour GiveUpBehaviour;
/*!

*/
			Boolean GiveUpBehaviour_RespawnAfter;
/*!
If not 0, we use this number of laps instead of the number defined in the map
*/
			Integer LapCountOverride;
/*!

*/
			Boolean UseMultiClans;
/*!

*/
			Boolean UseClans;
/*!

*/
			Boolean UseForcedClans;
/*!

*/
			Boolean UsePvPCollisions;
/*!

*/
			Boolean UseGuns;
/*!

*/
			Boolean UsePvPWeapons;
/*!

*/
			Boolean UseInterractiveScreensIn3d;
/*!

*/
			Boolean UseLaserVsBullets;
/*!

*/
			Boolean UseLaserSkewering;
/*!

*/
			Boolean UsePlayerTagging;
/*!

*/
			Boolean UseBeaconsWithRecipients;
/*!

*/
			Boolean UseAmmoBonusOnHit;
/*!

*/
			Boolean UseSameWallJump;
/*!

*/
			Boolean UseDefaultActionEvents;
/*!

*/
			Boolean UseLaunchedCheckpoints;
/*!

*/
			Boolean TrustClientSimu_FallbackToLatestReceivedState;
/*!

*/
			Boolean UseProtectClanmates;
/*!

*/
			Boolean UseAllies;
/*!

*/
			Integer GameplayVersion;
/*!

*/
			CSmMode::EGameplay Gameplay;
/*!

*/
			Real Mood_GetTimeOfDay();
/*!

*/
			Void Mood_SetTimeOfDay(Real Time01);
/*!

*/
			Integer Mood_GetDayDuration();
/*!

*/
			Boolean Mood_IsNight();
/*!

*/
			Real OffZoneRadius;
/*!

*/
			Real OffZoneRadiusSpeed;
/*!

*/
			Ident OffZoneCenterLandmarkId;
/*!

*/
	const	Integer PlayersNbTotal;
/*!

*/
	const	Integer PlayersNbAlive;
/*!

*/
	const	Integer PlayersNbDead;
/*!

*/
	const	Integer ClansNbTotal;
/*!

*/
	const	Integer ClansNbAlive;
/*!

*/
	const	Integer ClansNbDead;
/*!

*/
	const	Array<Integer> ClansNbPlayers;
/*!

*/
	const	Array<Integer> ClansNbPlayersAlive;
/*!

*/
	const	Array<CSmPlayer> Players;
/*!

*/
	const	Array<CSmPlayer> BotPlayers;
/*!

*/
	const	Array<CSmPlayer> Spectators;
/*!

*/
	const	Array<CSmPlayer> AllPlayers;
/*!

*/
	const	Array<CSmModeEvent> PendingEvents;
/*!

*/
			CSmPlayer GetPlayer(CUIConfig UI);
/*!

*/
			CSmPlayer GetPlayer(Text Login);
/*!

*/
	const	Array<CSmMapBase> MapBases;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_PlayerSpawn;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Gauge;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Sector;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_BotPath;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_BotSpawn;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_ObjectAnchor;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Gate;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Foundation;
/*!

*/
			Integer UiScoresPointsLimit;
/*!

*/
	const	Array<CSmScore> Scores;
/*!

*/
			Array<Integer> ClanScores;
/*!

*/
			Void SetGameModeNameAndCustomData(Text GameModeName,Text GameModeCustomData);
/*!

*/
			Void SetClubLogoUrl(Text ClubLogoUrl);
/*!

*/
			Void SetDecoImageUrl_DecalSponsor4x1(Text ImageUrl);
/*!

*/
			Void SetDecoImageUrl_Screen16x9(Text ImageUrl);
/*!

*/
			Void SetDecoImageUrl_Screen8x1(Text ImageUrl);
/*!

*/
			Void SetDecoImageUrl_Screen16x1(Text ImageUrl);
/*!

*/
			Void PassOn(CSmModeEvent Event);
/*!

*/
			Void Discard(CSmModeEvent Event);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapSpawn PlayerSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,CModeTurret Turret,Integer ActivationDate);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,CModeVehicle Vehicle,Integer ActivationDate);
/*!

*/
			Void SpawnPlayer(CSmPlayer Player,Integer ClanNum,CModeVehicle Vehicle,Integer SlotIndex,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapSpawn PlayerSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapBotPath BotPath,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,Integer ClanNum,Integer Armor,CMapBotSpawn BotSpawn,Integer ActivationDate);
/*!

*/
			Void SpawnBotPlayer(CSmPlayer Player,CSmPlayer Owner,Integer Armor,Vec3 Offset,Integer ActivationDate);
/*!

*/
			Void UnspawnPlayer(CSmPlayer Player);
/*!

*/
	const	CSmMode::ESmScoreSortOrder Scores_SortCriteria;
/*!

*/
			Boolean Scores_AutoUpdateLadderRank;
/*!

*/
			Void Scores_SetSortCriteria(CSmMode::ESmScoreSortOrder Criteria);
/*!

*/
			Void Scores_ComputeLadderRank(CSmMode::ESmScoreSortOrder Criteria);
/*!

*/
			Void Scores_ClearAll();
/*!

*/
			Void Score_ClearPrevRace(CSmScore Score);
/*!

*/
			Void Score_ClearPrevLap(CSmScore Score);
/*!

*/
			Void Score_Clear(CSmScore Score);
/*!

*/
			Void SetPlayerClan(CSmPlayer Player,Integer ClanNum);
/*!

*/
			Void SetPlayerWeapon(CSmPlayer Player,CSmMode::EWeapon DefaultWeapon,Boolean AutoSwitchWeapon);
/*!

*/
			Void SetPlayerWeaponAvailable(CSmPlayer Player,CSmMode::EWeapon Weapon,Boolean Available);
/*!

*/
			Void SetPlayerAllWeaponAvailable(CSmPlayer Player,Boolean Available);
/*!

*/
			Void SetPlayerReloadAllWeapons(CSmPlayer Player,Boolean ReloadAllWeapons);
/*!

*/
			Void SetPlayerAmmo(CSmPlayer Player,CSmMode::EWeapon Weapon,Integer Count);
/*!

*/
			Integer GetPlayerAmmo(CSmPlayer Player,CSmMode::EWeapon Weapon);
/*!

*/
			Void AddPlayerAmmo(CSmPlayer Player,CSmMode::EWeapon Weapon,Real DeltaCount);
/*!

*/
			Void SetPlayerAmmoMax(CSmPlayer Player,CSmMode::EWeapon Weapon,Integer Count);
/*!

*/
			Integer GetPlayerAmmoMax(CSmPlayer Player,CSmMode::EWeapon Weapon);
/*!

*/
			Void Entity_AddArmor(CEntity Victim,Integer DeltaArmor,CEntity Shooter,Integer ShooterPoints);
/*!

*/
			Void Entity_RemoveArmor(CEntity Victim,Integer DeltaArmor,CEntity Shooter,Integer ShooterPoints);
/*!

*/
			Void Entity_TriggerTurbo(CEntity Target,Integer StartTime);
/*!

*/
			Integer GetWeaponNum(CSmMode::EWeapon Weapon);
/*!

*/
			Boolean CanRespawnPlayer(CSmPlayer Player);
/*!

*/
			Void RespawnPlayer(CSmPlayer Player);
/*!

*/
			Void RespawnPlayer(CSmPlayer Player,CMapWaypoint Waypoint);
/*!

*/
			Void RespawnPlayer(CSmPlayer Player,CMapSpawn Spawn);
/*!

*/
			CSmPlayer CreateBotPlayer(Ident ModelId,Integer ClanNum);
/*!

*/
			Void DestroyBotPlayer(CSmPlayer BotPlayer);
/*!

*/
			Void DestroyAllBotPlayers();
/*!

*/
			Boolean Bots_AutoSpawn;
/*!

*/
			Boolean Bots_AutoRespawn;
/*!

*/
			Boolean Bots_AutoIgnoreBotEvents;
/*!
Navigation maps are needed for bots to move. If the current map has bot paths or items the navigation maps will always be computed, otherwise you will need to set this explicitely to True. May be necessary if you use CreateBotPlayer or SetNbFakePlayers.
*/
			Boolean ForceNavMapsComputation;
/*!

*/
			Void ActionLoad(CSmPlayer Player,CSmMode::EActionSlot ActionSlot,Ident ModelId);
/*!

*/
			Void ActionLoad(CSmPlayer Player,CSmMode::EActionSlot ActionSlot,Ident ModelId,Boolean MeleeMode);
/*!

*/
			Void ActionLoad(CModeVehicle Vehicle,Integer VehicleSlotIndex,CSmMode::EActionSlot ActionSlot,Ident ModelId);
/*!

*/
			Void ActionLoad(CModeTurret Turret,CSmMode::EActionSlot ActionSlot,Ident ModelId);
/*!

*/
			Integer Action_GetCooldown(CSmPlayer Player,CSmMode::EActionInput ActionInput);
/*!

*/
			Integer Action_GetRemainingCooldown(CSmPlayer Player,CSmMode::EActionInput ActionInput);
/*!

*/
			Void ActionBind(CSmPlayer Player,CSmMode::EActionSlot ActionSlot,CSmMode::EActionInput ActionInput);
/*!

*/
			Void ActionSetVariant(CSmPlayer Player,CSmMode::EActionSlot ActionSlot,Integer ActionVariant);
/*!

*/
			Void SetNbFakePlayers(Integer NbClan1,Integer NbClan2);
/*!

*/
	const	Array<CSmObject> Objects;
/*!

*/
			CSmObject ObjectCreate(Ident ModelId);
/*!

*/
			Void ObjectDestroy(CSmObject Object);
/*!

*/
			Void ObjectDestroyAll();
/*!

*/
			Void RemoveShieldArmor(Integer VictimShieldId,Integer Damage);
/*!

*/
			Void Replay_SaveAttackScore(CSmPlayer Player,Integer Score);
/*!

*/
			Void Replay_SaveDefenseScore(CSmPlayer Player,Integer Score);
/*!

*/
			Void Replay_SaveTeamScore(Integer Team,Integer Score);
/*!

*/
			Void Replay_SavePlayerOfInterest(CSmPlayer Player);
/*!

*/
			Void Replay_SaveWinner(CSmPlayer Player);
/*!

*/
			Void Replay_SaveInterface();
/*!

*/
			Void Player_BeginNewRace(CSmPlayer Player,Integer AbsoluteTime);
/*!

*/
			Void Player_BeginNewLap(CSmPlayer Player,Integer RaceTime);
/*!

*/
			Void Player_RemoveLastWaypointTime(CSmPlayer Player);
/*!

*/
			Void Player_AddWaypointTime(CSmPlayer Player,Integer Time);
/*!

*/
			Void Player_SetFinishTime(CSmPlayer Player,Integer Time);
/*!

*/
			Void Player_ClearRaceWaypointTimes(CSmPlayer Player);
/*!

*/
			Void Player_ClearLapWaypointTimes(CSmPlayer Player);
/*!

*/
			Void Player_ClearCurrentLapNumber(CSmPlayer Player);
/*!

*/
			Void Player_SetCurRaceAsBestRace(CSmPlayer Player);
/*!

*/
			Void Player_SetCurRaceAsPrevRace(CSmPlayer Player);
/*!

*/
			Void Player_SetCurLapAsBestLap(CSmPlayer Player);
/*!

*/
			Void Player_SetCurLapAsPrevLap(CSmPlayer Player);
/*!
Only available in solo mode and map is loaded.
*/
	const	CGhostManager GhostMgr;
/*!

*/
			Void Ghosts_SetStartTime(Integer StartTime);
/*!

*/
			Void Ghosts_SetMaxAlpha(Real MaxAlpha);
/*!

*/
			CGhost Ghost_RetrieveFromPlayer(CSmPlayer Player);
/*!

*/
			CGhost Ghost_RetrieveFromPlayer(CSmPlayer Player,Boolean TruncateLaunchedWaypointsRespawns);
};

/*!
* \brief An action
*
* Supported declare modes :
* - Local
*/
class CSmAction : public CAction {
public :
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Variant;
/*!

*/
	const	Array<CSmPlayer> Players;
/*!

*/
	const	CSmPlayer Owner;
/*!

*/
	const	CModeVehicle OwnerVehicle;
/*!

*/
	const	Boolean IsActive;
/*!

*/
	const	Boolean IsBound;
/*!
Is true only once during action init. Allow to init state variables
*/
	const	Boolean IsInitialFrame;
/*!

*/
			Integer Energy;
/*!

*/
			Integer EnergyMax;
/*!

*/
			Integer EnergyCost;
/*!

*/
			Boolean EnergyReload;
/*!

*/
			Real AmmoGain;
/*!

*/
			Ident State_EntityId1;
/*!

*/
			Integer State_Integer1;
/*!

*/
			Integer State_Integer2;
/*!

*/
			Boolean State_Boolean1;
/*!

*/
	const	Array<CSmActionEvent> PendingEvents;
/*!

*/
			Boolean IsJumping;
/*!

*/
			Boolean IsGliding;
/*!

*/
			Boolean IsAttractor;
/*!

*/
			Boolean IsFlying;
/*!

*/
			Boolean IsSliding;
/*!

*/
			Boolean IsRunning;
/*!

*/
			Boolean IsFrozen;
/*!

*/
			Boolean IsSneaking;
/*!

*/
			Boolean IsFreeLooking;
/*!

*/
			Boolean HasNoPlayerCollision;
/*!

*/
			Void SendRulesEvent(Text Param1,Array<Text> Param2,CEntity Shooter,CEntity Victim);
/*!

*/
			Ident Anim_GetModelId(Text ModelName);
/*!

*/
			Ident Anim_PlayAtLocation(Ident AnimModelId,Vec3 Position,Vec3 Direction);
/*!

*/
			Ident Anim_PlayOnPlayer(Ident AnimModelId,CSmPlayer Player);
/*!

*/
			Void Anim_Stop(Ident AnimId);
/*!

*/
			Ident Projectile_GetModelId(Text ModelName);
/*!

*/
			Ident Projectile_CreateAtLocation(Ident ProjectileModelId,CSmPlayer PlayerToIgnore,Vec3 InitialPosition,Vec3 InitialDirection,Vec3 InitialVelocity);
/*!

*/
			Ident Projectile_CreateOnPlayer(Ident ProjectileModelId,CSmPlayer Shooter);
/*!

*/
			Integer Cooldown;
/*!

*/
			Boolean Cooldown_IsReady();
/*!

*/
			Void Cooldown_Start();
/*!

*/
			Ident Shield_CreateAtLocation(Vec3 Position,Vec3 Direction);
/*!

*/
			Ident Shield_CreateOnPlayer(CSmPlayer ShieldOwner);
/*!

*/
			Void Shield_Destroy(Ident ShieldId);
/*!

*/
			Boolean Shield_Exists(Ident ShieldId);
/*!

*/
			Integer Shield_GetArmor(Ident ShieldId);
/*!

*/
			Void Shield_SetArmor(Ident ShieldId,Integer ShieldArmor);
/*!

*/
			Boolean Shield_GetIsActive(Ident ShieldId);
/*!

*/
			Void Shield_SetIsActive(Ident ShieldId,Boolean ShieldIsActive);
/*!

*/
			Integer Shield_GetArmorMax(Ident ShieldId);
/*!

*/
			Integer Shield_GetTickReload(Ident ShieldId);
/*!

*/
			Integer Shield_GetCooldown(Ident ShieldId);
/*!

*/
			Integer GetPlayerAmmo(CSmPlayer Player);
/*!

*/
			Integer GetPlayerAmmoMax(CSmPlayer Player);
/*!

*/
			Void Vehicle_TriggerTurbo();
/*!

*/
			Void Vehicle_TriggerTurboBrake();
/*!

*/
			Boolean Focus_Request();
/*!

*/
			Void Focus_Release();
/*!

*/
	const	Boolean Focus_Active;
/*!

*/
	const	Boolean Focused_Main;
/*!

*/
	const	Boolean Focused_Secondary;
/*!

*/
	const	Boolean Focused_Activable1;
/*!

*/
	const	Boolean Focused_Activable2;
/*!

*/
	const	Boolean Focused_Activable3;
/*!

*/
	const	Boolean Focused_Activable4;
/*!

*/
	const	Boolean Focused_Activable5;
/*!

*/
	const	Boolean Focused_Activable6;
/*!

*/
	const	Boolean Focused_Activable7;
/*!

*/
	const	Boolean Focused_Activable8;
/*!

*/
	const	Boolean Focused_Activable9;
/*!

*/
	const	Boolean Focused_Activable0;
/*!

*/
	const	Boolean Focused_Consumable1;
/*!

*/
	const	Boolean Focused_Consumable2;
/*!

*/
			Integer Focused_Scroll;
/*!

*/
			Integer Focused_Scroll_Max;
};

/*!
* \brief API for the plugins of the map editor.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CSmMapType : public CMapType {
public :
/*!

*/
	const	CSmMode Mode;
/*!

*/
	const	Array<CSmPlayer> AllPlayers;
/*!

*/
	const	Array<CSmPlayer> Players;
};

/*!
* \brief Documentation for class CNod
*/
class CNod {
public :
/*!

*/
	const	Ident Id;
};

/*!
* \brief This is the title menus Manialink interface.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaAppTitleLayer : public CMlScript {
public :
/*!
Will be Null if the script is not runing in a layer of an app.
*/
	const	CManiaAppTitle ParentApp;
/*!

*/
	const	CTitleControl TitleControl;
};

/*!
* \brief This is the stations Manialink interface.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMlStation : public CMlScript {
public :
/*!
Will be Null if the script is not runing in a layer of an app.
*/
	const	CManiaAppStation ParentApp;
/*!

*/
	const	CStation Station;
/*!

*/
			Void EnterStation();
};

/*!
* \brief API for GameModes Manialinks
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMlScriptIngame : public CMlScript {
public :
	/*!
	
	*/
	enum EUISound {
		Default,
		Silence,
		StartMatch,
		EndMatch,
		StartRound,
		EndRound,
		PhaseChange,
		TieBreakPoint,
		TiePoint,
		VictoryPoint,
		Capture,
		TimeOut,
		Notice,
		Warning,
		PlayerEliminated,
		PlayerHit,
		Checkpoint,
		Finish,
		Record,
		ScoreProgress,
		RankChange,
		Bonus,
		FirstHit,
		Combo,
		PlayersRemaining,
		Custom1,
		Custom2,
		Custom3,
		Custom4,
	};
	/*!
	
	*/
	enum EInGameMenuResult {
		Resume,
		Quit,
		NormalMenu,
		AdvancedMenu,
		ServerSettings,
	};
/*!

*/
	const	Integer GameTime;
/*!

*/
	const	CPlaygroundClient Playground;
/*!
(read-only) UI actually displayed, as defined by the server.
*/
			CUIConfig UI;
/*!
Locally accessible by the client script to locally override settings from the server.
*/
			CUIConfig ClientUI;
/*!
Is in spectator mode - may be only for a short time between rounds.
*/
	const	Boolean IsSpectator;
/*!
Client actually desires to spectate instead of playing.
*/
	const	Boolean IsSpectatorClient;
/*!

*/
	const	Boolean UseClans;
/*!

*/
	const	Boolean UseForcedClans;
/*!
Will be Null if the script is not runing in a layer of an app.
*/
	const	CManiaAppPlaygroundCommon ParentApp;
/*!

*/
	const	CMap Map;
/*!

*/
			Void ShowCurChallengeCard();
/*!

*/
			Void ShowModeHelp();
/*!

*/
			Void CopyServerLinkToClipBoard();
/*!

*/
			Void JoinTeam1();
/*!

*/
			Void JoinTeam2();
/*!

*/
	const	Array<CTeam> Teams;
/*!
Request change of IsSpectatorClient (not immediate, and it may be refused).
*/
			Void RequestSpectatorClient(Boolean Spectator);
/*!
Set the spectated player, but do not switch to spectator mode automatically. Equivalent to numpad1/2/3/4
*/
			Void SetSpectateTarget(Text Player);
/*!

*/
			Void ShowProfile(Text Player);
/*!

*/
			Void ShowInGameMenu();
/*!

*/
			Void CloseInGameMenu(CMlScriptIngame::EInGameMenuResult Result);
/*!

*/
			Void CloseScoresTable();
/*!

*/
	const	Boolean IsInGameMenuDisplayed;
/*!

*/
	const	Text CurrentServerLogin;
/*!

*/
	const	Text CurrentServerName;
/*!

*/
	const	Text CurrentServerDesc;
/*!

*/
	const	Text CurrentServerJoinLink;
/*!

*/
	const	Text CurrentServerModeName;
/*!

*/
	const	Integer SplitScreenNum;
/*!

*/
	const	Integer SplitScreenCount;
/*!

*/
	const	Boolean SplitScreenIsHorizontal;
/*!

*/
			Void PlayUiSound(CMlScriptIngame::EUISound Sound,Integer SoundVariant,Real Volume);
/*!

*/
	const	CAchievementsManager AchievementsManager;
};

/*!
* \brief This is the Manialink browser interface.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMlBrowser : public CMlScript {
public :
	/*!
	
	*/
	enum EBuddyResult {
		Ok,
		Error,
		NotFinished,
	};
/*!
Will be Null if the script is not runing in a layer of an app.
*/
	const	CManiaAppBrowser ParentApp;
/*!

*/
	const	CMap CurMap;
/*!

*/
			Void ShowCurMapCard();
/*!

*/
	const	CMlBrowser::EBuddyResult BuddyDoResult;
/*!

*/
	const	Text BuddyDoErrorMessage;
/*!

*/
	const	Boolean IsInBrowser;
/*!

*/
			Void BrowserBack();
/*!

*/
			Void BrowserQuit();
/*!

*/
			Void BrowserHome();
/*!

*/
			Void BrowserReload();
/*!

*/
			Text BrowserFocusedFrameId;
/*!

*/
			Void SetLocalUserClubLink(Text ClubLink);
};

/*!
* \brief This is the base Manialink page interface.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMapEditorPluginLayer : public CMlScript {
public :
/*!

*/
	const	CMapEditorPlugin Editor;
};

/*!
* \brief Documentation for class CMlPage
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMlPage : public CNod {
public :
/*!

*/
	const	CMlFrame MainFrame;
/*!

*/
			CMlControl GetFirstChild(Text ControlId);
/*!

*/
	const	CMlControl FocusedControl;
/*!

*/
			Boolean LinksInhibited;
/*!

*/
			Void GetClassChildren(Text Class,CMlFrame Frame,Boolean Recursive);
/*!

*/
	const	Array<CMlControl> GetClassChildren_Result;
/*!

*/
			Void ScrollToControl(CMlControl Control);
};

/*!
* \brief User profile.
*
* Supported declare modes :
* - Local
* - Persistent
* - Cloud
*/
class CUser : public CNod {
public :
	/*!
	
	*/
	enum EEchelon {
		None,
		Bronze1,
		Bronze2,
		Bronze3,
		Silver1,
		Silver2,
		Silver3,
		Gold1,
		Gold2,
		Gold3,
	};
	/*!
	
	*/
	enum ETagType {
		Bronze,
		Silver,
		Gold,
		Nadeo,
	};
	/*!
	
	*/
	enum EStereoDisplayMode {
		None,
		Stereo,
		HMD,
	};
	/*!
	
	*/
	enum EMuteSetting {
		Auto,
		Muted,
		NotMuted,
	};
/*!

*/
	const	Text Login;
/*!

*/
	const	Text WebServicesUserId;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text AvatarUrl;
/*!

*/
	const	Text ZonePath;
/*!

*/
	const	Text ZoneFlagUrl;
/*!

*/
	const	Text CountryFlagUrl;
/*!

*/
	const	Text Language;
/*!

*/
	const	Text Description;
/*!

*/
	const	Vec3 Color;
/*!

*/
	const	Text ClubLink;
/*!

*/
	const	Text Trigram;
/*!

*/
	const	Text BroadcastTVLogin;
/*!

*/
	const	Text SteamUserId;
/*!

*/
	const	Integer FameStars;
/*!

*/
	const	CUser::EEchelon Echelon;
/*!

*/
	const	Integer NextEchelonPercent;
/*!

*/
	const	Boolean IsBeginner;
/*!

*/
	const	Integer LadderRank;
/*!

*/
	const	Integer LadderTotal;
/*!

*/
	const	Real LadderPoints;
/*!

*/
	const	Text LadderZoneName;
/*!

*/
	const	Text LadderZoneFlagUrl;
/*!

*/
	const	Real ReferenceScore;
/*!

*/
	const	Boolean IsFakeUser;
/*!

*/
	const	Array<Integer> Tags_Favored_Indices;
/*!

*/
	const	Array<Text> Tags_Id;
/*!

*/
	const	Array<CUser::ETagType> Tags_Type;
/*!

*/
	const	Array<Text> Tags_Comments;
/*!

*/
	const	Array<Text> Tags_Deliverer;
/*!

*/
	const	CUser::EStereoDisplayMode StereoDisplayMode;
/*!

*/
			Boolean HackCamHmdDisabled;
/*!

*/
	const	Text AvatarDisplayName;
/*!

*/
	const	Text HornDisplayName;
/*!

*/
	const	Text Model_CarSport_SkinName;
/*!

*/
	const	Text Model_CarSport_SkinUrl;
/*!

*/
	const	Text Model_HelmetPilot_SkinName;
/*!

*/
	const	Text Model_HelmetPilot_SkinUrl;
/*!

*/
	const	Boolean VoiceChat_Supported;
/*!

*/
			CUser::EMuteSetting VoiceChat_MuteSetting;
/*!

*/
	const	Boolean VoiceChat_IsSpeaking;
/*!

*/
	const	Boolean VoiceChat_IsMuted;
/*!

*/
	const	Boolean IsConnectedToMasterServer;
/*!

*/
	const	Array<Text> AlliesConnected;
};

/*!
* \brief Documentation for class CTitle
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CTitle : public CNod {
public :
/*!

*/
	const	Text TitleId;
/*!

*/
	const	Text AuthorLogin;
/*!

*/
	const	Text AuthorName;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Desc;
/*!

*/
	const	Text InfoUrl;
/*!

*/
	const	Text DownloadUrl;
/*!

*/
	const	Text TitleVersion;
/*!

*/
	const	Text MakerTitleId;
/*!

*/
	const	Text BaseTitleId;
};

/*!
* \brief Events for Manialink page scripts.
*
* Supported declare modes :
* - Local
*/
class CMlScriptEvent : public CBaseConstEvent {
public :
	/*!
	
	*/
	enum Type {
		KeyPress,
		MouseClick,
		MouseRightClick,
		MouseOver,
		MouseOut,
		EntrySubmit,
		MenuNavigation,
		PluginCustomEvent,
	};
	/*!
	
	*/
	enum EMenuNavAction {
		Up,
		Right,
		Left,
		Down,
		Select,
		Cancel,
		PageUp,
		PageDown,
		AppMenu,
		Action1,
		Action2,
		ScrollUp,
		ScrollDown,
	};
/*!

*/
	const	CMlScriptEvent::Type Type;
/*!

*/
	const	Integer KeyCode;
/*!

*/
	const	Text KeyName;
/*!

*/
	const	Text CharPressed;
/*!

*/
	const	Text ControlId;
/*!

*/
	const	CMlControl Control;
/*!

*/
	const	CMlScriptEvent::EMenuNavAction MenuNavAction;
/*!

*/
	const	Boolean IsActionAutoRepeat;
/*!

*/
	const	Text CustomEventType;
/*!

*/
	const	Array<Text> CustomEventData;
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlControl : public CNod {
public :
	/*!
	
	*/
	enum AlignHorizontal {
		Left,
		HCenter,
		Right,
		None,
	};
	/*!
	
	*/
	enum AlignVertical {
		Top,
		VCenter,
		Bottom,
		None,
		VCenter2,
	};
/*!

*/
	const	CMlFrame Parent;
/*!

*/
	const	Text ControlId;
/*!

*/
	const	Array<Text> ControlClasses;
/*!

*/
			Boolean HasClass(Text Class);
/*!

*/
			Vec2 Size;
/*!

*/
			CMlControl::AlignHorizontal HorizontalAlign;
/*!

*/
			CMlControl::AlignVertical VerticalAlign;
/*!

*/
			Boolean Visible;
/*!

*/
			Vec2 RelativePosition_V3;
/*!

*/
			Real ZIndex;
/*!

*/
			Real RelativeScale;
/*!

*/
			Real RelativeRotation;
/*!

*/
	const	Vec2 AbsolutePosition_V3;
/*!

*/
	const	Real AbsoluteScale;
/*!

*/
	const	Real AbsoluteRotation;
/*!

*/
			Boolean DataAttributeExists(Text DataName);
/*!

*/
			Text DataAttributeGet(Text DataName);
/*!

*/
			Void DataAttributeSet(Text DataName,Text DataValue);
/*!

*/
			Text ToolTip;
/*!

*/
			Void Show();
/*!

*/
			Void Hide();
/*!

*/
			Void Focus();
/*!

*/
			Void ScriptEvents_Disable();
/*!

*/
			Void ScriptEvents_Restore();
/*!

*/
	const	Boolean IsFocused;
};

/*!
* \brief Tool for parsing document
*/
class CParsingManager : public CNod {
public :
/*!

*/
			CParsingDocument Create(Text Contents);
/*!

*/
			CParsingDocument Create(Text Contents,Boolean GenerateText,Boolean GenerateTextRaw,Boolean GenerateTextResursive);
/*!

*/
			Void Destroy(CParsingDocument Document);
/*!
Parses an XML document
*/
			CParsingDocument Parse_Xml(Text Contents);
/*!
Parses an XML document
*/
			CParsingDocument Parse_Xml(Text Contents,Boolean GenerateText,Boolean GenerateTextRaw,Boolean GenerateTextResursive);
/*!

*/
			Void Parse_Destroy(CParsingDocument Document);
/*!

*/
			Integer DocumentsSlotsLimit;
/*!

*/
	const	Array<CParsingDocument> DocumentsXml;
/*!

*/
			Ident Compose_Start_Xml(Boolean Compact);
/*!

*/
			Ident Compose_Start_Json(Boolean Compact);
/*!

*/
			Void Compose_End(Ident ComposerId);
/*!

*/
			Void Compose_Destroy(Ident ComposerId);
/*!

*/
			Void Compose_Node_Open(Ident ComposerId,Text Name);
/*!

*/
			Void Compose_Node_Close(Ident ComposerId);
/*!

*/
			Void Compose_Array_Open(Ident ComposerId,Text Name);
/*!

*/
			Void Compose_Array_Close(Ident ComposerId);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Text Value);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Integer Value);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Real Value);
/*!

*/
			Void Compose_Attribute(Ident ComposerId,Text Name,Boolean Value);
/*!

*/
			Void Compose_Value(Ident ComposerId,Text Name,Text Value);
/*!

*/
			Text Compose_GetResult(Ident ComposerId);
};

/*!
* \brief Manager for HTTP requests
*/
class CHttpManager : public CNod {
public :
/*!
Create a get request, AdditionnalHeaders format is : "Header-name: Value\nOther-name: OtherValue"
*/
			CHttpRequest CreateGet(Text Url);
/*!

*/
			CHttpRequest CreateGet(Text Url,Boolean UseCache);
/*!

*/
			CHttpRequest CreateGet(Text Url,Boolean UseCache,Text AdditionalHeaders);
/*!

*/
			CHttpRequest CreatePost(Text Url,Text Resource);
/*!

*/
			CHttpRequest CreatePost(Text Url,Text Resource,Text AdditionalHeaders);
/*!

*/
			CHttpRequest CreatePostFile(Text Url,Text FileName,Text AdditionalHeaders);
/*!

*/
			Void Destroy(CHttpRequest Request);
/*!

*/
			Boolean IsValidUrl(Text Url);
/*!

*/
	const	Array<CHttpRequest> Requests;
/*!

*/
	const	Integer SlotsAvailable;
/*!

*/
	const	Array<CHttpEvent> PendingEvents;
/*!

*/
			Boolean AutomaticHeaders_Timezone;
};

/*!
* \brief Documentation for class CVideoManager
*/
class CVideoManager : public CNod {
public :
/*!

*/
			CVideo CreateVideo(Text Url,Boolean IsLooping,Boolean AutoProcessing);
/*!

*/
			Void DestroyVideo(CVideo Video);
/*!

*/
	const	Array<CVideo> Videos;
};

/*!
* \brief Documentation for class CAudioManager
*/
class CAudioManager : public CNod {
public :
	/*!
	
	*/
	enum ELibSound {
		Alert,
		ShowDialog,
		HideDialog,
		ShowMenu,
		HideMenu,
		Focus,
		Valid,
		Start,
		Countdown,
		Victory,
		ScoreIncrease,
		Checkpoint,
	};
/*!

*/
			CAudioSource CreateSound(Text Url);
/*!

*/
			CAudioSource CreateSound(Text Url,Real VolumedB,Boolean IsMusic,Boolean IsLooping,Boolean IsSpatialized);
/*!

*/
			Void DestroySound(CAudioSource Sound);
/*!

*/
	const	Array<CAudioSource> Sounds;
/*!

*/
			CAudioSourceMusic CreateMusic(Text Url);
/*!

*/
			Void DestroyMusic(CAudioSourceMusic Music);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(CAudioManager::ELibSound Sound,Integer SoundVariant,Real VolumedB);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(CAudioManager::ELibSound Sound,Integer SoundVariant,Real VolumedB,Integer Delay);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB,Vec3 PanRadiusLfe);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB,Vec3 PanRadiusLfe);
/*!

*/
			Void PlaySoundEvent(CAudioSource Sound,Real VolumedB,Vec3 PanRadiusLfe,Integer Delay);
/*!

*/
			Void PlaySoundEvent(Text Url,Real VolumedB,Vec3 PanRadiusLfe,Integer Delay);
/*!

*/
			Void ClearAllDelayedSoundsEvents();
/*!

*/
			Boolean ForceEnableMusic;
/*!

*/
			Real LimitMusicVolumedB;
/*!

*/
			Real LimitSceneSoundVolumedB;
/*!

*/
			Real LimitUiSoundVolumedB;
};

/*!
* \brief Input devices.
*/
class CInputManager : public CNod {
public :
	/*!
	
	*/
	enum EButton {
		Left,
		Right,
		Up,
		Down,
		A,
		B,
		X,
		Y,
		L1,
		R1,
		LeftStick,
		RightStick,
		Menu,
		View,
		LeftStick_Left,
		LeftStick_Right,
		LeftStick_Up,
		LeftStick_Down,
		RightStick_Left,
		RightStick_Right,
		RightStick_Up,
		RightStick_Down,
		L2,
		R2,
		None,
	};
/*!

*/
	const	Array<CInputEvent> PendingEvents;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Period;
/*!

*/
	const	Array<CInputPad> Pads;
/*!

*/
	const	Vec2 MousePos;
/*!

*/
	const	Vec2 MouseKineticScrollVel;
/*!

*/
	const	Boolean MouseLeftButton;
/*!

*/
	const	Boolean MouseRightButton;
/*!

*/
	const	Boolean MouseMiddleButton;
/*!

*/
	const	Array<Vec2> TouchPoints_Cur;
/*!

*/
	const	Array<Vec2> TouchPoints_Init;
/*!

*/
			Text GetPadButtonPlaygroundBinding(CInputPad Pad,CInputManager::EButton Button);
/*!

*/
			Text GetPadButtonCurrentBinding(CInputPad Pad,CInputManager::EButton Button);
/*!

*/
			Text GetActionBinding(CInputPad Pad,Text ActionMap,Text ActionId);
/*!

*/
			Text GetActionDisplayName(Text ActionMap,Text ActionId);
/*!

*/
			Boolean ExclusiveMode;
/*!

*/
			Boolean IsKeyPressed(Integer KeyCode);
/*!
Duration (ms) elapsed since latest user interraction on any device.
*/
	const	Integer TimeSinceLatestActivity;
/*!

*/
	const	Integer TimeSinceLatestMouseActivity;
/*!

*/
	const	Integer TimeSinceLatestTouchActivity;
/*!

*/
	const	Integer TimeSinceLatestKeyboardActivity;
/*!

*/
	const	Integer TimeSinceLatestPadActivity;
};

/*!
* \brief Script API to manage game data.
*/
class CDataFileMgr : public CNod {
public :
	/*!
	
	*/
	enum EMediaType {
		Image,
		Sound,
		Script,
		MatchSettings,
		Module,
		Skins,
	};
/*!
Array of task results.
*/
	const	Array<CTaskResult> TaskResults;
/*!
Release a task result no more used.
*/
			Void TaskResult_Release(Ident TaskId);
/*!
Array of campaigns.
*/
	const	Array<CCampaign> Campaigns;
/*!
Get a campaign from its id.
*/
			CCampaign Campaign_Get(Text CampaignId);
/*!

*/
			Void Map_RefreshFromDisk();
/*!
Get the list of map stored in the user slot/dir.
*/
			CTaskResult_MapList Map_GetUserList(Ident UserId);
/*!
Get the list of map stored in the specified path.
*/
			CTaskResult_MapList Map_GetGameList(Text Path,Boolean Flatten);
/*!
Get the list of map stored according to the filters in the specified path.
*/
			CTaskResult_MapList Map_GetGameList(Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!
Get the list of map stored in the specified path. Scope is used to specify if the list is retrieved from game data (1), title data (2) or user data (4), which can be added).
*/
			CTaskResult_MapList Map_GetFilteredGameList(Integer Scope,Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!

*/
			CTaskResult_NSMap Map_NadeoServices_Get(Ident UserId,Text MapId);
/*!

*/
			CTaskResult_NSMap Map_NadeoServices_GetFromUid(Ident UserId,Text MapUid);
/*!

*/
			CTaskResult_NSMapList Map_NadeoServices_GetList(Ident UserId,Array<Text> MapIdList);
/*!

*/
			CTaskResult_NSMapList Map_NadeoServices_GetListFromUid(Ident UserId,Array<Text> MapUidList);
/*!

*/
			CTaskResult_NSMapList Map_NadeoServices_GetListFromUser(Ident UserId,Text WebServicesUserId);
/*!

*/
			CTaskResult_NSMap Map_NadeoServices_Register(Ident UserId,Text MapUid);
/*!

*/
			CTaskResult_NSSkin Skin_NadeoServices_Get(Ident UserId,Text SkinId);
/*!

*/
			CTaskResult_NSSkin Skin_NadeoServices_GetFromChecksum(Ident UserId,Text SkinChecksum);
/*!

*/
			CTaskResult_NSSkinList Skin_NadeoServices_GetList(Ident UserId,Array<Text> SkinIdList);
/*!

*/
			CTaskResult_NSSkinList Skin_NadeoServices_GetListFromChecksum(Ident UserId,Array<Text> SkinChecksumList);
/*!

*/
			CTaskResult_NSSkinList Skin_NadeoServices_GetListFromUser(Ident UserId,Text WebServicesUserId);
/*!

*/
			CTaskResult_NSSkin Skin_NadeoServices_Register(Ident UserId,Text SkinDisplayName,Text SkinFileName);
/*!

*/
			CTaskResult AccountSkin_NadeoServices_AddFavorite(Ident UserId,Text SkinId);
/*!

*/
			CTaskResult_NSSkinList AccountSkin_NadeoServices_GetFavoriteList(Ident UserId);
/*!

*/
			CTaskResult_NSSkinList AccountSkin_NadeoServices_GetList(Ident UserId);
/*!

*/
			CTaskResult AccountSkin_NadeoServices_RemoveFavorite(Ident UserId,Text SkinId);
/*!

*/
			CTaskResult_NSSkin AccountSkin_NadeoServices_Set(Ident UserId,Text SkinId);
/*!

*/
			CTaskResult AccountSkin_NadeoServices_Unset(Ident UserId,Text SkinType);
/*!
Array of ghosts.
*/
	const	Array<CGhost> Ghosts;
/*!
Release a downloaded ghost no longer needed.
*/
			Void Ghost_Release(Ident GhostId);
/*!

*/
			CTaskResult_Ghost Ghost_Download(Text FileName,Text Url);
/*!

*/
			CTaskResult Ghost_Upload(Text Url,CGhost Ghost,Text AdditionalHeaders);
/*!

*/
			Void Replay_RefreshFromDisk();
/*!
Get the list of replay stored in the specified path.
*/
			CTaskResult_ReplayList Replay_GetGameList(Text Path,Boolean Flatten);
/*!
Get the list of replay stored according to the filters in the specified path.
*/
			CTaskResult_ReplayList Replay_GetGameList(Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!
Get the list of replay stored in the specified path. Scope is used to specify if the list is retrieved from game data (1), title data (2) or user data (4), which can be added.
*/
			CTaskResult_ReplayList Replay_GetFilteredGameList(Integer Scope,Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!
Get the list of ghosts from the replay stored at the specified file path.
*/
			CTaskResult_GhostList Replay_Load(Text Path);
/*!
Save the map and the ghost into a replay file stored at the specified path.
*/
			CTaskResult Replay_Save(Text Path,CMap Map,CGhost Ghost);
/*!

*/
			CTaskResult Replay_Author_Save(CMap Map,CGhost Ghost);
/*!
Get the list of media stored in the specified path.
*/
			CTaskResult_FileList Media_GetGameList(CDataFileMgr::EMediaType Type,Text Path,Boolean Flatten);
/*!
Get the list of media stored according to the filters in the specified path.
*/
			CTaskResult_FileList Media_GetGameList(CDataFileMgr::EMediaType Type,Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!
Get the list of media stored in the specified path. Scope is used to specify if the list is retrieved from game data (1), title data (2) or user data (4), which can be added.
*/
			CTaskResult_FileList Media_GetFilteredGameList(CDataFileMgr::EMediaType Type,Integer Scope,Text Path,Boolean Flatten,Boolean SortByNameElseByDate,Boolean SortOrderAsc);
/*!

*/
			CTaskResult_GameModeList GameMode_GetGameList(Integer Scope,Text Path,Boolean Flatten);
/*!

*/
			CTaskResult Pack_DownloadOrUpdate(Text DisplayName,Text Url);
};

/*!
* \brief Score and leaderboard manager.
*/
class CScoreMgr : public CNod {
public :
	/*!
	
	*/
	enum ELocalScoreStatus {
		None,
		Loading,
		NotLoaded,
		Loaded,
	};
	/*!
	
	*/
	enum EMasterServerScoreStatus {
		None,
		Synchronizing,
		NotSynchronized,
		Synchronized,
	};
/*!
Array of task results.
*/
	const	Array<CTaskResult> TaskResults;
/*!
Release a task result no more used.
*/
			Void TaskResult_Release(Ident TaskId);
/*!
Returns the local status of user records for the specified context.
*/
			CScoreMgr::ELocalScoreStatus ScoreStatus_GetLocalStatusForContext(Ident UserId,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData);
/*!
Returns the masterserver status of user records for the specified context.
*/
			CScoreMgr::EMasterServerScoreStatus ScoreStatus_GetMasterServerStatusForContext(Ident UserId,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData);
/*!
Returns the ghost currently being recorded for a player on the current playground. (or the latest ghost if the player is not playing.)
*/
			CGhost Playground_GetPlayerGhost(CPlayer GamePlayer);
/*!
Set a new record for a map.
*/
			CTaskResult Map_SetNewRecord_v2(Ident UserId,Text MapUid,Text GameMode,Text GameModeCustomData,CGhost Ghost);
/*!
Returns the user record time for a map.
*/
			Integer Map_GetRecord_v2(Ident UserId,Text MapUid,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData);
/*!
Returns the user record ghost for  a map.
*/
			CTaskResult_Ghost Map_GetRecordGhost_v2(Ident UserId,Text MapUid,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData);
/*!
Returns the number of medals for a map.
*/
			Integer Map_GetMedal(Ident UserId,Text MapUid,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData);
/*!
Returns the record score of the medal for a map.
*/
			Integer Map_GetMultiAsyncLevelRecord_v2(Text MapUid,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData,Integer MultiAsyncLevel);
/*!
Returns the record ghost of the medal for a map.
*/
			CTaskResult_Ghost Map_GetMultiAsyncLevelRecordGhost_v2(Text MapUid,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData,Integer MultiAsyncLevel);
/*!
Returns the skillpoints for a map.
*/
			Integer Map_GetSkillPoints_v2(Ident UserId,Text MapUid,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData);
/*!

*/
			CTaskResult_MapRecordList Map_GetPlayerListRecordList(Ident UserId,Array<Text> WebServicesUserIdList,Text MapUid,Text ScopeType,Text ScopeId,Text GameMode,Text GameModeCustomData);
/*!

*/
			CWebServicesTaskResult_Natural MapLeaderBoard_GetPlayerRankingAsync(Ident UserId,Text MapUid,Text Context,Text Zone);
/*!
Returns the number of medals for a campaign.
*/
			Integer Campaign_GetMultiAsyncLevel(Ident UserId,Text CampaignId);
/*!
Returns the number of medals of the specified level for a campaign.
*/
			Integer Campaign_GetMultiAsyncLevelCount(Ident UserId,Text CampaignId,Integer MultiAsyncLevel);
/*!
Returns the skillpoints for a campaign.
*/
			Integer Campaign_GetSkillPoints(Ident UserId,Text CampaignId);
/*!
Returns the all the records of an opponent specified by its login for a campaign.
*/
			CTaskResult_MapRecordList Campaign_GetOpponentRecords(Ident UserId,Text CampaignId,Text OpponentLogin);
/*!
Returns the buddies records for a map of a campaign.
*/
			CTaskResult_BuddiesChallengeRecord Campaign_GetBuddiesMapRecord(Ident UserId,Text CampaignId,Text MapUid);
/*!
Returns if the buddies records for a map of a campaign are dirty.
*/
			Boolean Campaign_IsBuddiesMapRecordDirty(Ident UserId,Text CampaignId,Text MapUid);
/*!
Returns the buddies records comparison for a campaign.
*/
			CTaskResult_BuddiesChallengeRecordsComparison Campaign_GetBuddiesMapRecordsComparison(Ident UserId,Text CampaignId);
/*!
Returns the records comparison with a buddy for a campaign.
*/
			CTaskResult_BuddyChallengeRecordsComparison Campaign_GetBuddyMapRecordsComparison(Ident UserId,Text OpponentLogin,Text CampaignId);
/*!
Returns the user ranking on a campaign.
*/
			CWebServicesTaskResult_Natural CampaignLeaderBoard_GetPlayerRankingAsync(Ident UserId,Text CampaignId,Text Zone,Boolean UseSkillPoints);
/*!
Returns the number of user ranked on a campaign.
*/
			Integer CampaignLeaderBoard_GetPlayerCount(Text CampaignId,Text Zone,Boolean UseSkillPoints);
/*!
Returns a part of the campaign leaderboard.
*/
			CTaskResult_NaturalLeaderBoardInfoList CampaignLeaderBoard_GetPlayerList(Ident UserId,Text CampaignId,Text Zone,Boolean UseSkillPoints,Integer FromIndex,Integer Count);
/*!
Creates a new season.
*/
			CTaskResult_Season Season_Create(Ident UserId,Text SeasonName,Text GameMode,Text GameModeCustomData,Text MapRecordType,Integer StartTimeStamp,Integer EndTimeStamp,Array<Text> MapUidList);
/*!

*/
			CTaskResult_Season Season_Update(Ident UserId,Text SeasonId,Text SeasonName,Text GameMode,Text GameModeCustomData,Text MapRecordType,Integer StartTimeStamp,Integer EndTimeStamp,Array<Text> MapUidList);
/*!

*/
			CTaskResult_Season Season_AddMapList(Ident UserId,Text SeasonId,Array<Text> MapUidList);
/*!

*/
			CTaskResult_Season Season_RemoveMapList(Ident UserId,Text SeasonId,Array<Text> MapUidList);
/*!
Returns the season info from a season id.
*/
			CTaskResult_Season Season_Get(Ident UserId,Text SeasonId);
/*!
Returns a list of season info from a list of season id.
*/
			CTaskResult_SeasonList Season_GetList(Ident UserId,Array<Text> SeasonIdList);
/*!
Returns the list of created season from a webservices user id.
*/
			CTaskResult_SeasonList Season_GetListFromUser(Ident UserId,Text WebServicesUserId);
/*!
Loads and synchronizes season scores.
*/
			CTaskResult Season_LoadScore(Ident UserId,Text SeasonId);
/*!

*/
			CTaskResult_MapRecordList Season_GetOpponentRecordList(Ident UserId,Text SeasonId,Text OpponentWebServicesUserId);
/*!
Add points to multiplayer score.
*/
			Void Multiplayer_AddToScore(Ident UserId,Real ScoreDiff,Integer Timestamp);
/*!
Returns the multiplayer ranking.
*/
			Integer MultiplayerLeaderBoard_GetPlayerRanking(Ident UserId,Text Zone);
/*!
Returns the number of user ranked in multiplayer leaderboard.
*/
			Integer MultiplayerLeaderBoard_GetPlayerCount(Text Zone);
/*!
Returns the user global ranking.
*/
			Integer GlobalLeaderBoard_GetPlayerRanking(Ident UserId,Text Zone);
/*!
Returns the number of user ranked in global leaderboard.
*/
			Integer GlobalLeaderBoard_GetPlayerCount(Text Zone);
/*!
Returns a part of the global leaderboard.
*/
			CTaskResult_RealLeaderBoardInfoList GlobalLeaderBoard_GetPlayerList(Ident UserId,Text Zone,Integer FromIndex,Integer Count);
/*!
Returns the account trophy summary for the last year.
*/
			CTaskResult_AccountTrophyLastYearSummary Trophy_GetLastYearSummary(Ident UserId);
/*!
Returns the account trophy summary for the last year for the specified user
*/
			CTaskResult_AccountTrophyLastYearSummary Trophy_GetLastYearSummaryForUser(Ident UserId,Text WebServicesUserId);
/*!
Returns the trophy solo medal achievement settings
*/
			CTaskResult_TrophySoloMedalAchievementSettings Trophy_GetSoloMedalAchievementSettings(Ident UserId,Text SoloMedalAchievementType);
};

/*!
* \brief Documentation for class CRankingsZoneMgr
*/
class CRankingsZoneMgr : public CNod {
public :
/*!

*/
	const	Array<CTaskResult> TaskResults;
/*!

*/
			Void TaskResult_Release(Ident TaskId);
/*!

*/
			Void GetPathAndName(Text ZoneFullPath,Text ZonePath,Text ZoneName);
/*!

*/
			CTaskResult_ZoneList GetZoneList(Array<Text> ZoneIdList);
/*!

*/
			CTaskResult_ZoneList GetChildZoneList(Text ZoneFullPath);
/*!

*/
			CTaskResult SetUserZone(Ident UserId,Text ZoneFullPath);
};

/*!
* \brief API for local users/profiles.
*/
class CUserV2Manager : public CNod {
public :
	/*!
	
	*/
	enum EUbisoftClubFlow {
		OverView,
		Auth,
		Reward,
		Rewards,
		Actions,
	};
	/*!
	
	*/
	enum EUplayOverlaySection {
		Achievements,
		Actions,
		Challenges,
		Chat,
		Current,
		Friends,
		GameOptions,
		Home,
		Party,
		PendingGameInvites,
		ProductActivation,
		Rewards,
		Shop,
	};
/*!

*/
	const	CUserV2Profile MainUserProfile;
/*!

*/
	const	Array<CTaskResult> TaskResults;
/*!

*/
			Void TaskResult_Release(Ident TaskId);
/*!
NullId for the mainuser.
*/
			CTaskResult_StringIntList GetGroups(Ident UserId);
/*!

*/
	const	CMasterServerUser MainUserWebServicesInfo;
/*!

*/
			CTaskResult_Session_Get LiveSession_GetInfo(Ident UserId,Text SessionId);
/*!

*/
			Void LiveSession_ShowInviteUI(Ident UserId);
/*!

*/
			CTaskResult UbisoftClub_Launch(Ident UserId,CUserV2Manager::EUbisoftClubFlow UbisoftClubFlow,Text RewardId);
/*!

*/
			CTaskResult UbisoftClub_LaunchAndCompleteActions(Ident UserId,CUserV2Manager::EUbisoftClubFlow UbisoftClubFlow,Text RewardId,Array<Text> ActionIdList);
/*!

*/
			CTaskResult Uplay_OpenOverlay(Ident UserId,CUserV2Manager::EUplayOverlaySection OverlaySection);
};

/*!
* \brief Documentation for class CAnimManager
*/
class CAnimManager : public CNod {
public :
	/*!
	
	*/
	enum EAnimManagerEasing {
		Linear,
		QuadIn,
		QuadOut,
		QuadInOut,
		CubicIn,
		CubicOut,
		CubicInOut,
		QuartIn,
		QuartOut,
		QuartInOut,
		QuintIn,
		QuintOut,
		QuintInOut,
		SineIn,
		SineOut,
		SineInOut,
		ExpIn,
		ExpOut,
		ExpInOut,
		CircIn,
		CircOut,
		CircInOut,
		BackIn,
		BackOut,
		BackInOut,
		ElasticIn,
		ElasticOut,
		ElasticInOut,
		ElasticIn2,
		ElasticOut2,
		ElasticInOut2,
		BounceIn,
		BounceOut,
		BounceInOut,
	};
/*!

*/
			Void Add(CMlControl Control,Text XmlTarget,Integer StartTime,Integer Duration,CAnimManager::EAnimManagerEasing EasingFunc);
/*!

*/
			Void AddChain(CMlControl Control,Text XmlTarget,Integer Duration,CAnimManager::EAnimManagerEasing EasingFunc);
/*!

*/
			Void Add(CMlControl Control,Text XmlTarget,Integer Duration,CAnimManager::EAnimManagerEasing EasingFunc);
/*!

*/
			Void Flush(CMlControl Control);
};

/*!
* \brief Create scenes for use in menus with <Camera> manialink element
*/
class CMenuSceneManager : public CNod {
public :
/*!
LayoutFileName: can be 'Default' (or '') for default painter scene, 'Empty' for a simple empty scene, or a filename to game data.
*/
			Ident SceneCreate(Text LayoutFileName);
/*!

*/
			Void SceneDestroy(Ident SceneId);
/*!
SkinNameOrUrl: can be 'Skins/Model/....', 'http://....', 'Default' (or '') for item default skin, 'Profile' for the user choice for the model. ModelName: item filename.
*/
			Ident ItemCreate(Ident SceneId,Text ModelName,Text SkinName,Text SkinUrl);
/*!

*/
			Void ItemDestroy(Ident SceneId,Ident ItemId);
};

/*!
* \brief Documentation for class CSystemPlatform
*
* Supported declare modes :
* - Local
*/
class CSystemPlatform : public CNod {
public :
	/*!
	
	*/
	enum ESystemPlatform {
		None,
		Steam,
		UPlay,
		PS4,
		XBoxOne,
	};
	/*!
	
	*/
	enum ESystemSkuIdentifier {
		Unknown,
		EU,
		US,
		JP,
	};
/*!

*/
	const	CSystemPlatform::ESystemPlatform Platform;
/*!

*/
	const	CSystemPlatform::ESystemSkuIdentifier SkuIdentifier;
/*!

*/
	const	Text ExeVersion;
/*!

*/
	const	Integer CurrentLocalDate;
/*!

*/
	const	Text CurrentLocalDateText;
/*!

*/
	const	Text CurrentTimezone;
/*!

*/
	const	Text CurrentTimezoneTimeOffset;
/*!

*/
	const	Text ExtraTool_Info;
/*!

*/
			Text ExtraTool_Data;
/*!

*/
			Void ClipboardSet(Text ClipboardText);
};

/*!
* \brief API for a Title main menu.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaAppTitle : public CManiaApp {
public :
/*!

*/
	const	Array<CManiaAppEvent> PendingEvents;
/*!

*/
			Void Menu_Quit();
/*!

*/
			Void Menu_Home();
/*!

*/
			Void Menu_Solo();
/*!

*/
			Void Menu_Local();
/*!

*/
			Void Menu_Internet();
/*!

*/
			Void Menu_Editor();
/*!

*/
			Void Menu_Profile();
/*!

*/
			Boolean LoadingScreenRequireKeyPressed;
/*!

*/
			Boolean DontScaleMainMenuForHMD;
/*!

*/
	const	CTitleControl TitleControl;
/*!
Only available when editing a title.
*/
	const	CTitleEdition TitleEdition;
/*!

*/
	const	CNotificationsConsumer Notifications;
/*!

*/
	const	Text ExternalRequest_Type;
/*!

*/
	const	Array<Text> ExternalRequest_Data;
/*!
Call as soon as the request has been consumed and is being processed.
*/
			Void ExternalRequest_Clear();
/*!

*/
	const	CAchievementsManager AchievementsManager;
/*!

*/
	const	CBadgeManager BadgeManager;
/*!

*/
	const	CMatchSettingsManager MatchSettingsManager;
/*!

*/
	const	CMenuSceneManager MenuSceneManager;
/*!

*/
			Void Authentication_GetToken(Ident UserId,Text AppLogin);
/*!

*/
	const	Boolean Authentication_GetTokenResponseReceived;
/*!

*/
	const	Integer Authentication_ErrorCode;
/*!

*/
	const	Text Authentication_Token;
/*!

*/
			Boolean Adverts_UsePersonnalData;
/*!

*/
			Boolean Adverts_Enabled;
};

/*!
* \brief API for the plugins of the map editor.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMapEditorPlugin : public CManiaApp {
public :
	/*!
	
	*/
	enum CardinalDirections {
		North,
		East,
		South,
		West,
	};
	/*!
	
	*/
	enum CardinalDirections8 {
		North,
		East,
		South,
		West,
		NorthEast,
		SouthEast,
		SouthWest,
		NorthWest,
	};
	/*!
	
	*/
	enum RelativeDirections {
		Forward,
		RightForward,
		Right,
		RightBackward,
		Backward,
		LeftBackward,
		Left,
		LeftForward,
	};
	/*!
	
	*/
	enum PlaceMode {
		Unknown,
		Terraform,
		Block,
		Macroblock,
		Skin,
		CopyPaste,
		Test,
		Plugin,
		CustomSelection,
		OffZone,
		BlockProperty,
		Path,
		GhostBlock,
		Item,
		Light,
	};
	/*!
	
	*/
	enum EditMode {
		Unknown,
		Place,
		FreeLook,
		Erase,
		Pick,
		SelectionAdd,
		SelectionRemove,
	};
	/*!
	
	*/
	enum ShadowsQuality {
		NotComputed,
		VeryFast,
		Fast,
		Default,
		High,
		Ultra,
	};
	/*!
	
	*/
	enum ValidationStatus {
		NotValidable,
		Validable,
		Validated,
	};
/*!

*/
	const	Array<CMapEditorPluginEvent> PendingEvents;
/*!

*/
	const	CMap Map;
/*!

*/
	const	Text MapName;
/*!

*/
	const	Text MapFileName;
/*!

*/
	const	Boolean IsEditorReadyForRequest;
/*!

*/
			Boolean HoldLoadingScreen;
/*!

*/
			Void HideOtherPlugins();
/*!

*/
			Void ShowOtherPlugins();
/*!

*/
			Void ComputeShadows();
/*!

*/
			Void ComputeShadows(CMapEditorPlugin::ShadowsQuality ShadowsQuality);
/*!

*/
	const	CMapEditorPlugin::ShadowsQuality CurrentShadowsQuality;
/*!

*/
	const	Boolean IsUltraShadowsQualityAvailable;
/*!

*/
			Void DisplayDefaultSetObjectivesDialog();
/*!

*/
			Boolean Undo();
/*!

*/
			Boolean Redo();
/*!

*/
			Void Help();
/*!

*/
			Void Validate();
/*!

*/
			Void AutoSave();
/*!

*/
			Void Quit();
/*!

*/
			Void QuickQuit();
/*!

*/
			Void QuitAndSetResult(Text Type,Array<Text> Data);
/*!

*/
			Void QuickQuitAndSetResult(Text Type,Array<Text> Data);
/*!

*/
			Void TestMapFromStart();
/*!

*/
			Void TestMapFromCoord(Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Void TestMapWithMode(Text RulesModeName);
/*!

*/
			Void TestMapWithMode(Text RulesModeName,Text SettingsXml);
/*!

*/
			Void TestMapWithMode_SplitScreen(Text RulesModeName);
/*!

*/
			Void TestMapWithMode_SplitScreen(Text RulesModeName,Integer ScreenCount);
/*!

*/
			Void TestMapWithMode_SplitScreen(Text RulesModeName,Integer ScreenCount,Integer FakeCount,Text SettingsXml);
/*!

*/
			Boolean EnableMapTypeStartTest;
/*!

*/
			Void SaveMap(Text FileName);
/*!

*/
			Void SaveMapGamepadEditor(Text FileName);
/*!

*/
			Void SaveMap(Text FileName,Text Path);
/*!

*/
			CMapEditorPlugin::PlaceMode PlaceMode;
/*!

*/
			CMapEditorPlugin::EditMode EditMode;
/*!

*/
			Boolean UndergroundMode;
/*!

*/
			Boolean BlockStockMode;
/*!

*/
	const	CMapEditorInventory Inventory;
/*!

*/
			Real CameraVAngle;
/*!

*/
			Real CameraHAngle;
/*!

*/
			Real CameraToTargetDistance;
/*!

*/
			Vec3 CameraTargetPosition;
/*!

*/
	const	Vec3 CameraPosition;
/*!

*/
			Real ThumbnailCameraVAngle;
/*!

*/
			Real ThumbnailCameraHAngle;
/*!

*/
			Real ThumbnailCameraRoll;
/*!

*/
			Real ThumbnailCameraFovY;
/*!

*/
			Vec3 ThumbnailCameraPosition;
/*!

*/
			Boolean GetRaceCamera(Vec3 Position,Real Yaw,Real Pitch,Real Roll,Real FovY);
/*!

*/
			Boolean EnableAirMapping;
/*!

*/
			Boolean EnableMixMapping;
/*!

*/
			Void RemoveAllBlocks();
/*!

*/
			Void RemoveAllTerrain();
/*!

*/
			Void RemoveAllOffZone();
/*!

*/
			Void RemoveAllObjects();
/*!

*/
			Void RemoveAll();
/*!

*/
			Void RemoveAllBlocksAndTerrain();
/*!

*/
			Void ShowCustomSelection();
/*!

*/
			Void HideCustomSelection();
/*!

*/
			Void CopyPaste_Copy();
/*!

*/
			Void CopyPaste_Cut();
/*!

*/
			Void CopyPaste_Remove();
/*!

*/
			Void CopyPaste_SelectAll();
/*!

*/
			Void CopyPaste_ResetSelection();
/*!

*/
			Void OpenToolsMenu();
/*!

*/
			Void EditMediatrackIngame();
/*!

*/
			Void PreloadAllBlocks();
/*!

*/
			Void PreloadAllItems();
/*!

*/
			Boolean CanPlaceBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir,Boolean OnGround,Integer VariantIndex);
/*!

*/
			Boolean PlaceBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceGhostBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean PlaceGhostBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceBlock_NoDestruction(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir,Boolean OnGround,Integer VariantIndex);
/*!

*/
			Boolean PlaceBlock_NoDestruction(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceRoadBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean PlaceRoadBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean CanPlaceTerrainBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean PlaceTerrainBlocks(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean PlaceTerrainBlocks_NoDestruction(CBlockModel BlockModel,Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean CanPlaceMacroblock(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_AirMode(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceMacroblock_NoDestruction(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_NoDestruction(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean CanPlaceMacroblock_NoTerrain(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_NoTerrain(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean RemoveMacroblock(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean RemoveMacroblock_NoTerrain(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			CBlock GetBlock(Int3 Coord);
/*!

*/
			CBlock GetBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			CBlock GetGhostBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean IsBlockModelSkinnable(CBlockModel BlockModel);
/*!

*/
			Integer GetNbBlockModelSkins(CBlockModel BlockModel);
/*!

*/
			Text GetBlockModelSkin(CBlockModel BlockModel,Integer SkinIndex);
/*!

*/
			Text GetSkinDisplayName(Text SkinFileName);
/*!

*/
			Text GetBlockSkin(CBlock Block);
/*!

*/
			Void SetBlockSkin(CBlock Block,Text SkinFileName);
/*!

*/
			Boolean IsMacroblockModelSkinnable(CMacroblockModel BlockModel);
/*!

*/
			Boolean SetMacroblockSkin(CMacroblockInstance Macroblock,Text SkinFileName);
/*!

*/
			Boolean OpenBlockSkinDialog(CBlock Block);
/*!

*/
			Boolean RemoveBlock(Int3 Coord);
/*!

*/
			Boolean RemoveBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean RemoveGhostBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean RemoveTerrainBlocks(Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Integer GetBlockGroundHeight(CBlockModel BlockModel,Integer CoordX,Integer CoordZ,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Integer GetGroundHeight(Integer CoordX,Integer CoordZ);
/*!

*/
			Int3 GetMouseCoordOnGround();
/*!

*/
			Int3 GetMouseCoordAtHeight(Integer CoordY);
/*!

*/
			CBlock GetStartLineBlock();
/*!

*/
			Boolean RemoveItem(CAnchorData Item);
/*!

*/
			Void CopyPaste_AddOrSubSelection(Int3 StartCoord,Int3 EndCoord);
/*!

*/
			Boolean CopyPaste_Symmetrize();
/*!

*/
			Void SaveMacroblock(CMacroblockModel MacroblockModel);
/*!

*/
			CMacroblockModel GetMacroblockModelFromFilePath(Text MacroblockModelFilePath);
/*!

*/
			CBlockModel GetTerrainBlockModelFromName(Text TerrainBlockModelName);
/*!

*/
			CBlockModel GetBlockModelFromName(Text BlockModelName);
/*!

*/
			CBlockClipList CreateFrameClipList();
/*!

*/
			CBlockClipList CreateFixedClipList();
/*!

*/
			Void UnvalidateMetadata();
/*!

*/
			Void UnvalidateGameplayInfo();
/*!

*/
			Void UnvalidatePlayfield();
/*!

*/
			Boolean RemoveMacroblock_NoTerrain_NoUnvalidate(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean PlaceMacroblock_NoTerrain_NoUnvalidate(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Void GetConnectResults(CBlock ExistingBlock,CBlockModel NewBlock);
/*!

*/
			Void GetConnectResults(CBlock ExistingBlock,CMacroblockModel NewBlock);
/*!

*/
			Void GetConnectResults(CMacroblockInstance ExistingBlock,CBlockModel NewBlock);
/*!

*/
			Void GetConnectResults(CMacroblockInstance ExistingBlock,CMacroblockModel NewBlock);
/*!

*/
			Integer GetStartBlockCount(Boolean IncludeMultilaps);
/*!

*/
			Integer GetFinishBlockCount(Boolean IncludeMultilaps);
/*!

*/
			Integer GetMultilapBlockCount();
/*!

*/
			Integer GetCheckpointBlockCount();
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir,Integer UserData);
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir,CBlockClipList DefaultClipList);
/*!

*/
			CMacroblockInstance CreateMacroblockInstance(CMacroblockModel MacroblockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir,CBlockClipList DefaultClipList,Integer UserData);
/*!

*/
			CMacroblockInstance GetMacroblockInstanceFromOrder(Integer Order);
/*!

*/
			CMacroblockInstance GetMacroblockInstanceFromUnitCoord(Int3 Coord);
/*!

*/
			CMacroblockInstance GetLatestMacroblockInstance();
/*!

*/
			CMacroblockInstance GetLatestMacroblockInstance(Integer Offset);
/*!

*/
			CMacroblockInstance GetMacroblockInstanceConnectedToClip(CBlockClip Clip);
/*!

*/
			Boolean RemoveMacroblockInstance(CMacroblockInstance MacroblockInstance);
/*!

*/
			Boolean RemoveMacroblockInstanceFromOrder(Integer Order);
/*!

*/
			Boolean RemoveMacroblockInstanceFromUnitCoord(Integer Order);
/*!

*/
			Boolean RemoveMacroblockInstancesByUserData(Integer UserData);
/*!

*/
			Void ResetAllMacroblockInstances();
/*!

*/
			Integer GetMaxOrder();
/*!

*/
			Boolean SetMapType(Text MapType);
/*!

*/
			Text GetMapType();
/*!

*/
			Void SetMapStyle(Text MapStyle);
/*!

*/
			Text GetMapStyle();
/*!

*/
			Text GetAvailableMapName();
/*!

*/
			Vec3 GetVec3FromCoord(Int3 Coord);
/*!

*/
	const	CMapEditorCamera Camera;
/*!

*/
	const	CMapEditorCursor Cursor;
/*!

*/
	const	Array<CItemAnchor> Items;
/*!

*/
	const	Array<Text> MediatrackIngameClips;
/*!

*/
			Integer MediatrackIngameEditedClipIndex;
/*!

*/
	const	Array<CBlock> Blocks;
/*!

*/
	const	Array<CBlockModel> BlockModels;
/*!

*/
	const	Array<CBlockModel> TerrainBlockModels;
/*!

*/
	const	Array<CMacroblockModel> MacroblockModels;
/*!

*/
	const	Array<CBlock> ClassicBlocks;
/*!

*/
	const	Array<CBlock> TerrainBlocks;
/*!

*/
	const	Array<CBlock> GhostBlocks;
/*!

*/
	const	Array<CBlockClipList> FixedClipLists;
/*!

*/
	const	Array<CBlockClipList> FrameClipLists;
/*!

*/
	const	Array<CBlockClipList> MacroblockInstanceClipLists;
/*!

*/
	const	Array<CMacroblockInstance> MacroblockInstances;
/*!

*/
	const	Array<CMapEditorConnectResults> ConnectResults;
/*!

*/
	const	Array<CAnchorData> AnchorData;
/*!

*/
			Array<Int3> CustomSelectionCoords;
/*!

*/
			Vec3 CustomSelectionRGB;
/*!

*/
			Boolean EnableEditorInputsCustomProcessing;
/*!

*/
			Boolean EnableCursorShowingWhenInterfaceIsFocused;
/*!

*/
			Boolean HideEditorInterface;
/*!

*/
			Boolean HideBlockHelpers;
/*!

*/
			Boolean ShowPlacementGrid;
/*!

*/
	const	Boolean IsTesting;
/*!

*/
	const	Boolean IsValidating;
/*!

*/
	const	Boolean EditorInputIsDown_Menu;
/*!

*/
	const	Boolean EditorInputIsDown_SwitchToRace;
/*!

*/
	const	Boolean EditorInputIsDown_Undo;
/*!

*/
	const	Boolean EditorInputIsDown_Redo;
/*!

*/
	const	Boolean EditorInputIsDown_CursorUp;
/*!

*/
	const	Boolean EditorInputIsDown_CursorRight;
/*!

*/
	const	Boolean EditorInputIsDown_CursorDown;
/*!

*/
	const	Boolean EditorInputIsDown_CursorLeft;
/*!

*/
	const	Boolean EditorInputIsDown_CursorRaise;
/*!

*/
	const	Boolean EditorInputIsDown_CursorLower;
/*!

*/
	const	Boolean EditorInputIsDown_CursorTurn;
/*!

*/
	const	Boolean EditorInputIsDown_CursorPick;
/*!

*/
	const	Boolean EditorInputIsDown_CursorPlace;
/*!

*/
	const	Boolean EditorInputIsDown_CursorDelete;
/*!

*/
	const	Boolean EditorInputIsDown_CameraUp;
/*!

*/
	const	Boolean EditorInputIsDown_CameraRight;
/*!

*/
	const	Boolean EditorInputIsDown_CameraDown;
/*!

*/
	const	Boolean EditorInputIsDown_CameraLeft;
/*!

*/
	const	Boolean EditorInputIsDown_CameraZoomNext;
/*!

*/
	const	Boolean EditorInputIsDown_Camera0;
/*!

*/
	const	Boolean EditorInputIsDown_Camera1;
/*!

*/
	const	Boolean EditorInputIsDown_Camera3;
/*!

*/
	const	Boolean EditorInputIsDown_Camera7;
/*!

*/
	const	Boolean EditorInputIsDown_Camera9;
/*!

*/
	const	Boolean EditorInputIsDown_PivotChange;
/*!

*/
	const	Boolean EditorInputIsDown_CursorTurnSlightly;
/*!

*/
	const	Boolean EditorInputIsDown_CursorTurnSlightlyAntiClockwise;
/*!

*/
	const	Boolean EditorInputIsDown_IconUp;
/*!

*/
	const	Boolean EditorInputIsDown_IconRight;
/*!

*/
	const	Boolean EditorInputIsDown_IconDown;
/*!

*/
	const	Boolean EditorInputIsDown_IconLeft;
/*!

*/
	const	Boolean EditorInputIsDown_RemoveAll;
/*!

*/
	const	Boolean EditorInputIsDown_Save;
/*!

*/
	const	Boolean EditorInputIsDown_SaveAs;
/*!

*/
	const	Boolean EditorInputIsDown_MapStyle;
/*!

*/
	const	Boolean EditorInputIsDown_ClassicMapEditor;
/*!

*/
	const	Boolean EditorInputIsDown_SelectAll;
/*!

*/
	const	Boolean EditorInputIsDown_Copy;
/*!

*/
	const	Boolean EditorInputIsDown_Cut;
/*!

*/
	const	Boolean EditorInputIsDown_Paste;
/*!

*/
	const	Real CollectionSquareSize;
/*!

*/
	const	Real CollectionSquareHeight;
/*!

*/
	const	Integer CollectionGroundY;
/*!

*/
	const	CMapEditorPlugin::ValidationStatus ValidationStatus;
/*!

*/
			Text ManialinkText;
/*!

*/
	const	CMlPage ManialinkPage;
};

/*!
* \brief Documentation for class CUILayer
*/
class CUILayer : public CNod {
public :
	/*!
	
	*/
	enum EUILayerType {
		Normal,
		ScoresTable,
		ScreenIn3d,
		AltMenu,
		Markers,
		CutScene,
		InGameMenu,
		EditorPlugin,
		ManiaplanetPlugin,
		ManiaplanetMenu,
		LoadingScreen,
	};
	/*!
	
	*/
	enum EUILayerAnimation {
		None,
		DownFast,
		DownSlow,
		LeftFast,
		LeftSlow,
		RightFast,
		RightSlow,
		ScaleFast,
		ScaleSlow,
		UpFast,
		UpSlow,
	};
/*!

*/
			Boolean IsVisible;
/*!

*/
	const	Boolean AnimInProgress;
/*!

*/
			CUILayer::EUILayerType Type;
/*!

*/
			CUILayer::EUILayerAnimation InAnimation;
/*!

*/
			CUILayer::EUILayerAnimation OutAnimation;
/*!

*/
			CUILayer::EUILayerAnimation InOutAnimation;
/*!

*/
			Text AttachId;
/*!

*/
			Text ManialinkPage;
/*!

*/
	const	CMlPage LocalPage;
/*!

*/
	const	Boolean IsLocalPageScriptRunning;
};

/*!
* \brief User privileges manager.
*/
class CTrackingMgr : public CNod {
public :
/*!
Array of task results.
*/
	const	Array<CTaskResult> TaskResults;
/*!
Release a task result no more used.
*/
			Void TaskResult_Release(Ident TaskId);
/*!

*/
			Void Track_ContextMenuStart(Ident UserId,Text MenuName);
/*!

*/
			Void Track_ContextMenuStop(Ident UserId,Text MenuName);
/*!

*/
			Void Track_ContextGameModeStart(Ident UserId,Text GameMode);
/*!

*/
			Void Track_ContextGameModeStop(Ident UserId,Text GameMode);
/*!

*/
			Void Track_ContextMapStart(Ident UserId,Text MapUid,Text Environment);
/*!

*/
			Void Track_ContextMapStop(Ident UserId,Text MapUid);
/*!

*/
			Void Track_ContextPlayStart(Ident UserId,Text Type);
/*!

*/
			Void Track_ContextPlayStop(Ident UserId,Text Type,Text Reason,Integer NbRespawns);
/*!

*/
			Void Track_NewMapCreated(Ident UserId,Text Environment,Boolean IsRandomlyGenerated);
/*!

*/
			Void Track_NewsImpression(Ident UserId,Text NewsId);
/*!

*/
			Void Track_NewsClick(Ident UserId,Text NewsId);
/*!

*/
			Void Track_PlayerAchievement(Ident UserId,Integer AchievementId);
/*!

*/
			Void Track_StatOnline(Ident UserId,Integer Echelon);
/*!

*/
			Void Track_StatSeasonOfficial(Ident UserId,Integer PlayedMapCount,Integer BronzeMedalCount,Integer SilverMedalCount,Integer GoldMedalCount,Integer AuthorMedalCount,Integer MaxDifficultyLevel,Integer Year,Text Season);
/*!

*/
			Void Track_StatSeasonWeekly(Ident UserId,Integer PlayedMapCount,Integer BronzeMedalCount,Integer SilverMedalCount,Integer GoldMedalCount,Integer AuthorMedalCount,Integer MaxDifficultyLevel,Integer Year,Integer Week);
};

/*!
* \brief API for editor plugins.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CAnyEditorPlugin : public CManiaApp {
public :
	/*!
	
	*/
	enum EInteractionStatus {
		Active,
		Closed,
		Aborted,
	};
/*!

*/
	const	Array<CManiaAppEvent> PendingEvents;
/*!

*/
	const	CEditorModule ModuleEditor;
/*!

*/
	const	CEditorMesh MeshEditor;
/*!

*/
	const	CEditorEditor EditorEditor;
/*!

*/
	const	CEditorMediaTracker MediaTracker;
/*!

*/
	const	CEditorSkin SkinEditor;
/*!

*/
	const	CAnyEditorPlugin::EInteractionStatus InteractionStatus;
};

/*!
* \brief Documentation for class CEditorPluginHandle
*
* Supported declare modes :
* - Local
*/
class CEditorPluginHandle : public CNod {
public :
};

/*!
* \brief Documentation for class CMapInfo
*/
class CMapInfo : public CNod {
public :
/*!

*/
	const	Text MapUid;
/*!

*/
	const	Text Comments;
/*!

*/
	const	Integer CopperPrice;
/*!

*/
	const	Text CollectionName;
/*!

*/
	const	Text AuthorLogin;
/*!

*/
	const	Text AuthorNickName;
/*!

*/
	const	Text AuthorZonePath;
/*!

*/
	const	Text AuthorZoneFlagUrl;
/*!

*/
	const	Text AuthorCountryFlagUrl;
/*!

*/
	const	Text MapType;
/*!

*/
	const	Text MapStyle;
/*!

*/
	const	Boolean Unlocked;
/*!

*/
	const	Boolean IsPlayable;
/*!

*/
	const	Boolean CreatedWithSimpleEditor;
/*!

*/
	const	Boolean CreatedWithPartyEditor;
/*!

*/
	const	Boolean CreatedWithGamepadEditor;
/*!

*/
	const	Integer TMObjective_AuthorTime;
/*!

*/
	const	Integer TMObjective_GoldTime;
/*!

*/
	const	Integer TMObjective_SilverTime;
/*!

*/
	const	Integer TMObjective_BronzeTime;
/*!

*/
	const	Integer TMObjective_NbLaps;
/*!

*/
	const	Boolean TMObjective_IsLapRace;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Path;
/*!

*/
	const	Text FileName;
};

/*!
* \brief A currently connected CUser
*
* Supported declare modes :
* - Local
*/
class CClient : public CNod {
public :
/*!

*/
	const	CUser User;
/*!

*/
	const	CUIConfig UI;
/*!
Otherwise, it's a LAN account not currently authentified with the masterserver.
*/
	const	Boolean IsConnectedToMasterServer;
/*!

*/
	const	Text ClientVersion;
/*!

*/
	const	Text ClientTitleVersion;
/*!

*/
	const	Boolean IsSpectator;
/*!
Duration during which the player is not active while they should be (AFK).
*/
	const	Integer IdleDuration;
};

/*!
* \brief This object handles the interface.
*
* Supported declare modes :
* - Local
* - NetworkRead
* - NetworkWrite
*/
class CUIConfig : public CNod {
public :
	/*!
	
	*/
	enum EUISequence {
		None,
		Playing,
		Intro,
		Outro,
		Podium,
		CustomMTClip,
		EndRound,
		PlayersPresentation,
		UIInteraction,
		RollingBackgroundIntro,
		CustomMTClip_WithUIInteraction,
		Finish,
	};
	/*!
	
	*/
	enum EUIStatus {
		None,
		Normal,
		Warning,
		Error,
		Official,
	};
	/*!
	
	*/
	enum EVisibility {
		None,
		Normal,
		Manual,
		ForcedHidden,
		ForcedVisible,
	};
	/*!
	
	*/
	enum ELabelsVisibility {
		None,
		Never,
		Always,
		WhenInFrustum,
		WhenVisible,
		WhenInMiddleOfScreen,
	};
	/*!
	
	*/
	enum EAvatarVariant {
		Default,
		Sad,
		Happy,
	};
	/*!
	
	*/
	enum EUISound {
		Default,
		Silence,
		StartMatch,
		EndMatch,
		StartRound,
		EndRound,
		PhaseChange,
		TieBreakPoint,
		TiePoint,
		VictoryPoint,
		Capture,
		TimeOut,
		Notice,
		Warning,
		PlayerEliminated,
		PlayerHit,
		Checkpoint,
		Finish,
		Record,
		ScoreProgress,
		RankChange,
		Bonus,
		FirstHit,
		Combo,
		PlayersRemaining,
		Custom1,
		Custom2,
		Custom3,
		Custom4,
	};
	/*!
	
	*/
	enum ENoticeLevel {
		Default,
		PlayerInfo,
		PlayerWarning,
		MapInfo,
		MapWarning,
		MatchInfo,
		MatchWarning,
	};
	/*!
	
	*/
	enum EMessageDisplay {
		Chat,
		Small,
		Status,
		Big,
	};
	/*!
	
	*/
	enum EObserverMode {
		Default,
		Forced,
		Forbidden,
		Manual,
	};
	/*!
	
	*/
	enum EHudVisibility {
		Nothing,
		Everything,
		MarkersOnly,
		Default,
	};
	/*!
	
	*/
	enum ECutSceneStyle {
		None,
		TM,
		SM,
	};
/*!

*/
			CUIConfig::EUISequence UISequence;
/*!

*/
	const	Boolean UISequenceIsCompleted;
/*!

*/
			Text UISequence_CustomMTClip;
/*!

*/
			Integer UISequence_CustomMTRefTime;
/*!

*/
			Boolean UISequence_CanSkipIntroMT;
/*!

*/
			Text UISequence_PodiumPlayersWin;
/*!

*/
			Text UISequence_PodiumPlayersLose;
/*!

*/
			CUIConfig::ECutSceneStyle UISequence_CutSceneStyle;
/*!

*/
			Boolean DisableZoomTransitions;
/*!

*/
			Text ManialinkPage;
/*!

*/
			Text BigMessage;
/*!

*/
			Text BigMessageAvatarLogin;
/*!

*/
			CUIConfig::EAvatarVariant BigMessageAvatarVariant;
/*!

*/
			CUIConfig::EUISound BigMessageSound;
/*!

*/
			Integer BigMessageSoundVariant;
/*!

*/
			Text StatusMessage;
/*!

*/
			Text GaugeMessage;
/*!

*/
			Real GaugeRatio;
/*!

*/
			Integer GaugeClan;
/*!
An XML text describing the map tooltips appearing in the HUD.<br/>It's a set of &lt;marker/&gt; elements which can have the following attributes : <ol><li>label : a text to display</li><li>pos : a vector of 3 world coordinates desribing the position of the marker</li><li>playerlogin : alternatively, instead of using pos, you can use a player login. The marker will smoothly follow the player</li><li>playerid : similar to playerlogin. Fill it with Player.MarkerId. The marker will smoothly follow the player</li><li>box : a vector of 3 dimensions describing the size of the marked object (allows a better placement of the marker on the screen)</li><li>gauge : a Real. If between 0. and 1. a gauge will be shown undeneath the text</li><li>imageurl : a string. URL of an image to use</li><li>distmax : a real. The marker will disappear if the dist to it is greater than distmax</li><li>isturning : a bool. Only for markers attached to players. If the marker appear on a minimap, it will turn around to reflect the player orientation.</li></ol>
*/
			Text MarkersXML;
/*!

*/
			Boolean OverrideMarkers;
/*!

*/
	const	Array<CUIConfigMarker> Markers;
/*!

*/
	const	Array<CUILayer> UILayers;
/*!

*/
			Boolean OverlayHideNotices;
/*!

*/
			Boolean OverlayHideMapInfo;
/*!

*/
			Boolean OverlayHideOpponentsInfo;
/*!

*/
			Boolean OverlayHideChat;
/*!

*/
			Boolean OverlayHideCheckPointList;
/*!

*/
			Boolean OverlayHideRoundScores;
/*!

*/
			Boolean OverlayHideCountdown;
/*!

*/
			Boolean OverlayHideCrosshair;
/*!

*/
			Boolean OverlayHideGauges;
/*!

*/
			Boolean OverlayHideConsumables;
/*!

*/
			Boolean OverlayHide321Go;
/*!

*/
			Boolean OverlayMute321Go;
/*!

*/
			Boolean OverlayHideBackground;
/*!

*/
			Boolean OverlayHideChrono;
/*!

*/
			Boolean OverlayHideSpeedAndDist;
/*!

*/
			Boolean OverlayHidePersonnalBestAndRank;
/*!

*/
			Boolean OverlayHidePosition;
/*!

*/
			Boolean OverlayHideCheckPointTime;
/*!

*/
			Boolean OverlayHideEndMapLadderRecap;
/*!

*/
			Boolean OverlayHideMultilapInfos;
/*!

*/
			Boolean OverlayHideSpectatorControllers;
/*!

*/
			Boolean OverlayHideSpectatorInfos;
/*!

*/
			Boolean OverlayChatHideAvatar;
/*!
Values in range (0 - 40)
*/
			Integer OverlayChatLineCount;
/*!

*/
			Vec2 OverlayChatOffset;
/*!

*/
			Vec2 CountdownCoord;
/*!

*/
			Boolean NoticesFilter_HidePlayerInfo;
/*!

*/
			Boolean NoticesFilter_HidePlayerWarning;
/*!

*/
			Boolean NoticesFilter_HidePlayerInfoIfNotMe;
/*!

*/
			Boolean NoticesFilter_HidePlayerWarningIfNotMe;
/*!

*/
			Boolean NoticesFilter_HideMapInfo;
/*!

*/
			Boolean NoticesFilter_HideMapWarning;
/*!

*/
			Boolean NoticesFilter_HideMatchInfo;
/*!

*/
			Boolean NoticesFilter_HideMatchWarning;
/*!

*/
			CUIConfig::ENoticeLevel NoticesFilter_LevelToShowAsBigMessage;
/*!

*/
			Text ScoreTable;
/*!

*/
			CUIConfig::EVisibility ScoreTableVisibility;
/*!

*/
			Text SmallScoreTable;
/*!

*/
			CUIConfig::EVisibility SmallScoreTableVisibility;
/*!

*/
			Boolean ScoreTableOnlyManialink;
/*!

*/
			Boolean AltMenuNoDefaultScores;
/*!

*/
			Boolean AltMenuNoCustomScores;
/*!

*/
			Boolean OverlayScoreSummary;
/*!

*/
			Ident ScoreSummary_Player1;
/*!

*/
			Integer ScoreSummary_Points1;
/*!

*/
			Integer ScoreSummary_RoundPoints1;
/*!

*/
			Integer ScoreSummary_MatchPoints1;
/*!

*/
			Real ScoreSummary_Gauge1;
/*!

*/
			Ident ScoreSummary_Player2;
/*!

*/
			Integer ScoreSummary_Points2;
/*!

*/
			Integer ScoreSummary_RoundPoints2;
/*!

*/
			Integer ScoreSummary_MatchPoints2;
/*!

*/
			Real ScoreSummary_Gauge2;
/*!

*/
			Boolean ScreenIn3dHideScoreSummary;
/*!

*/
			Boolean ScreenIn3dHideVersus;
/*!

*/
			Integer CountdownEndTime;
/*!

*/
			CUIConfig::EUIStatus UIStatus;
/*!

*/
			CUIConfig::EHudVisibility LabelsVisibility;
/*!

*/
			CUIConfig::ELabelsVisibility AlliesLabelsVisibility;
/*!

*/
			CUIConfig::EVisibility AlliesLabelsShowGauges;
/*!

*/
			CUIConfig::EVisibility AlliesLabelsShowNames;
/*!
Values in range (0 - 250)
*/
			Integer AlliesLabelsMaxCount;
/*!

*/
			CUIConfig::ELabelsVisibility TeamLabelsVisibility;
/*!

*/
			CUIConfig::EVisibility TeamLabelsShowGauges;
/*!

*/
			CUIConfig::EVisibility TeamLabelsShowNames;
/*!

*/
			CUIConfig::ELabelsVisibility OpposingTeamLabelsVisibility;
/*!

*/
			CUIConfig::EVisibility OpposingTeamLabelsShowGauges;
/*!

*/
			CUIConfig::EVisibility OpposingTeamLabelsShowNames;
/*!

*/
			Boolean ForceSpectator;
/*!

*/
			Integer SpectatorForceCameraType;
/*!

*/
			Real SpectatorCamAutoLatitude;
/*!

*/
			Real SpectatorCamAutoLongitude;
/*!

*/
			Real SpectatorCamAutoRadius;
/*!
When not in spectator mode, allow/forbid to change the camera to observe other players. (in Trackmania there's no 'Manual' mode.)
*/
			CUIConfig::EObserverMode SpectatorObserverMode;
/*!

*/
			Void Spectator_SetAutoTarget_Clear();
/*!

*/
			Void Spectator_SetAutoTarget_All();
/*!

*/
			Void Spectator_SetAutoTarget_User(CUser User);
/*!

*/
			Void Spectator_SetForcedTarget_Clear();
/*!

*/
			Void Spectator_SetForcedTarget_AllPlayers();
/*!

*/
			Void Spectator_SetForcedTarget_AllMap();
/*!

*/
			Void Spectator_SetForcedTarget_Entity(CEntity Entity);
/*!

*/
			Void Spectator_SetForcedTarget_Landmark(CMapLandmark Landmark);
/*!
Only in local scripts, since ghosts are only known on the client.
*/
			Void Spectator_SetForcedTarget_Ghost(Ident GhostInstanceId);
/*!

*/
			Void Spectator_SetForcedTarget_Clan(Integer ClanNumber);
/*!

*/
			Void SendChat(Text Text);
/*!

*/
			Void SendNotice(Text Text,CUIConfig::ENoticeLevel Level,CUser Avatar,CUIConfig::EAvatarVariant AvatarVariant,CUIConfig::EUISound Sound,Integer SoundVariant);
/*!

*/
			Text GetLayerManialinkAction(CUILayer Layer);
/*!

*/
			Void ClearLayerManialinkAction(CUILayer Layer);
/*!

*/
			CUIConfigMarker AddMarker(Vec3 Position);
/*!

*/
			CUIConfigMarker AddMarker(CEntity Entity);
/*!

*/
			CUIConfigMarker AddMarker(CMapLandmark Landmark);
/*!

*/
			CUIConfigMarker AddMarker(Ident GhostInstanceId);
/*!

*/
			Void RemoveMarker(CUIConfigMarker Marker);
/*!

*/
			Void ClearMarkers();
/*!

*/
			Void QueueMessage(Integer Duration,Integer Priority,CUIConfig::EMessageDisplay Level,Text Message,CUser Avatar,CUIConfig::EAvatarVariant AvatarVariant,CUIConfig::EUISound Sound,Integer SoundVariant);
/*!

*/
			Void QueueMessage(Integer Duration,Integer Priority,CUIConfig::EMessageDisplay Level,Text Message,CUIConfig::EUISound Sound,Integer SoundVariant);
/*!

*/
			Void QueueMessage(Integer Duration,Integer Priority,CUIConfig::EMessageDisplay Level,Text Message);
/*!

*/
			Void ClearMessages();
};

/*!
* \brief Documentation for class CScore
*
* Supported declare modes :
* - Local
* - NetworkRead
* - NetworkWrite
*/
class CScore : public CNod {
public :
/*!

*/
	const	CUser User;
/*!

*/
	const	Boolean IsRegisteredForLadderMatch;
/*!

*/
	const	Real LadderScore;
/*!

*/
			Integer LadderRankSortValue;
/*!

*/
			Real LadderMatchScoreValue;
/*!

*/
			Integer LadderClan;
};

/*!
* \brief Documentation for class CTeam
*
* Supported declare modes :
* - Local
* - NetworkRead
* - NetworkWrite
*/
class CTeam : public CNod {
public :
/*!

*/
			Text Name;
/*!

*/
			Text ZonePath;
/*!

*/
			Text City;
/*!

*/
			Text EmblemUrl;
/*!

*/
			Text PresentationManialinkUrl;
/*!

*/
			Text ClubLinkUrl;
/*!

*/
			Vec3 ColorPrimary;
/*!

*/
			Vec3 ColorSecondary;
/*!

*/
	const	Text ColorText;
/*!

*/
	const	Text ColorizedName;
};

/*!
* \brief ServerPlugin Event
*
* Supported declare modes :
* - Local
*/
class CServerPluginEvent : public CBaseConstEvent {
public :
	/*!
	
	*/
	enum EType {
		Unknown,
		ClientConnected,
		ClientDisconnected,
		MapLoaded,
		BeginMatch,
		BeginRound,
		EndRound,
		EndMatch,
		MapUnloadRequested,
		MapUnloaded,
		ChatCommand,
		ChatMessage,
		ModeCallback,
	};
/*!
Event type.
*/
	const	CServerPluginEvent::EType Type;
/*!

*/
	const	CClient Client;
/*!

*/
	const	Text ChatText;
/*!

*/
	const	Text ChatCommandType;
/*!

*/
	const	Array<Text> ChatCommandData;
/*!

*/
	const	Text ModeCallbackType;
/*!

*/
	const	Array<Text> ModeCallbackData;
/*!

*/
	const	Array<CScore> EndMatchScores;
/*!

*/
	const	Array<Integer> EndMatchRanks;
};

/*!
* \brief Documentation for class CUIConfigMgr
*/
class CUIConfigMgr : public CNod {
public :
/*!

*/
			Void ResetAll();
/*!

*/
	const	CUIConfig UIAll;
/*!

*/
	const	Array<CUIConfig> UI;
/*!

*/
			CUIConfig GetUI(CPlayer Player);
/*!

*/
			CUIConfig GetUI(CUser User);
/*!

*/
			CUIConfig GetUI(CClient Client);
/*!

*/
	const	Array<CUILayer> UILayers;
/*!

*/
			CUILayer UILayerCreate();
/*!

*/
			Void UILayerDestroy(CUILayer Layer);
/*!

*/
			Void UILayerDestroyAll();
/*!

*/
	const	Array<CUILayer> UIReplayLayers;
/*!

*/
			Integer UISequenceMaxDuration;
/*!

*/
			Boolean HoldLoadingScreen;
/*!

*/
	const	Array<CUIConfigEvent> PendingEvents;
};

/*!
* \brief API for server control when playing online.
*/
class CServerAdmin : public CNod {
public :
	/*!
	
	*/
	enum ESpecMode {
		Selectable,
		SpectatorForced,
		PlayerForced,
		SpectatorSelectable,
		PlayerSelectable,
	};
/*!
ServerInfo
*/
	const	CServerInfo ServerInfo;
/*!

*/
			Void AutoTeamBalance();
/*!

*/
			Boolean Kick(CUser User,Text Reason);
/*!

*/
			Boolean Kick(CClient Client,Text Reason);
/*!

*/
			Boolean Ban(CUser User,Text Reason);
/*!

*/
			Boolean Ban(CClient Client,Text Reason);
/*!

*/
			Boolean ForceSpectator(CUser User,CServerAdmin::ESpecMode SpecMode);
/*!

*/
			Boolean ForceSpectator(CClient Client,CServerAdmin::ESpecMode SpecMode);
/*!

*/
			Boolean ForcePlayerRequestedTeam(CUser User,Integer Team);
/*!
Team is 1 or 2.
*/
			Boolean ForcePlayerRequestedTeam(CClient Client,Integer Team);
/*!
Disable Team change UI on the clients.
*/
			Boolean IsDisableChangeTeams;
/*!

*/
			Void SetLobbyInfo(Boolean IsLobby,Integer LobbyPlayerCount,Integer LobbyMaxPlayerCount,Real LobbyPlayersLevel);
/*!

*/
			Void SendToServerAfterMatch(Text ServerUrl);
/*!

*/
			Void CustomizeQuitDialog(Text ManialinkPage,Text SendToServerUrl,Boolean ProposeAddToFavorites,Integer ForceDelay);
/*!
Always use NullId as UserId.
*/
			Void Authentication_GetToken(Ident UserId,Text AppLogin);
/*!

*/
	const	Boolean Authentication_GetTokenResponseReceived;
/*!

*/
	const	Integer Authentication_ErrorCode;
/*!

*/
	const	Text Authentication_Token;
};

/*!
* \brief Documentation for class CXmlRpc
*
* Supported declare modes :
* - Local
* - NetworkRead
* - NetworkWrite
*/
class CXmlRpc : public CNod {
public :
/*!

*/
	const	Array<CXmlRpcEvent> PendingEvents;
/*!

*/
			Void SendCallback(Text Param1,Text Param2);
/*!

*/
			Void SendCallbackArray(Text Type,Array<Text> Data);
/*!

*/
			Void SendCallback_BeginRound();
/*!

*/
			Void SendCallback_EndRound();
};

/*!
* \brief Rules API for gamemodes.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMode : public CNod {
public :
	/*!
	
	*/
	enum EMedal {
		None,
		Finished,
		Bronze,
		Silver,
		Gold,
		Author,
	};
/*!

*/
	const	Array<CTaskResult> TaskResults;
/*!

*/
			Void TaskResult_Release(Ident TaskId);
/*!

*/
			Text ModeStatusMessage;
/*!

*/
	const	CTitle LoadedTitle;
/*!

*/
	const	Text ServerLogin;
/*!

*/
	const	Text ServerName;
/*!

*/
	const	Text ServerModeName;
/*!

*/
	const	Text MapName;
/*!

*/
	const	CMap Map;
/*!

*/
	const	Text MapPlayerModelName;
/*!

*/
	const	Array<CUser> Users;
/*!

*/
	const	Array<CTeam> Teams;
/*!

*/
			Text NeutralEmblemUrl;
/*!

*/
	const	Text ForcedClubLinkUrl1;
/*!

*/
	const	Text ForcedClubLinkUrl2;
/*!

*/
			Void TweakTeamColorsToAvoidHueOverlap();
/*!

*/
			Text ClientManiaAppUrl;
/*!

*/
	const	Integer Now;
/*!

*/
	const	Integer Period;
/*!

*/
			Boolean MatchEndRequested;
/*!

*/
	const	Boolean ServerShutdownRequested;
/*!

*/
	const	Boolean MapLoaded;
/*!

*/
			Void RequestLoadMap();
/*!

*/
			Void RequestUnloadMap();
/*!

*/
	const	Array<CMapInfo> MapList;
/*!

*/
			Integer NextMapIndex;
/*!

*/
	const	CUIConfigMgr UIManager;
/*!

*/
			Void Hud_Load(Text ModuleName);
/*!

*/
	const	CModulePlaygroundHud Hud;
/*!

*/
			Void PassOn(CUIConfigEvent EventToPassOn);
/*!

*/
			Void Discard(CUIConfigEvent EventToDiscard);
/*!

*/
			Void Ladder_OpenMatch_Request();
/*!

*/
			Void Ladder_AddPlayer(CScore PlayerScore);
/*!

*/
			Void Ladder_OpenMatch_BeginRequest();
/*!

*/
			Void Ladder_OpenMatch_AddPlayer(CScore PlayerScore);
/*!

*/
			Void Ladder_OpenMatch_EndRequest();
/*!

*/
			Void Ladder_CloseMatchRequest();
/*!

*/
			Void Ladder_CancelMatchRequest();
/*!

*/
	const	Boolean Ladder_RequestInProgress;
/*!

*/
			Void Ladder_SetResultsVersion(Integer Version);
/*!

*/
			Void Ladder_SetMatchMakingMatchId(Integer MatchId);
/*!

*/
			Void Ladder_EnableChallengeMode(Boolean Enable);
/*!

*/
			Void Trophy_LiveTimeAttackAchievement_AddResult(Text WebServicesUserId,Integer MatchRank,Integer TrophyRanking);
/*!

*/
			Void Trophy_LiveTimeAttackAchievement_ClearResultList();
/*!

*/
			CTaskResult_AccountTrophyGainList Trophy_LiveTimeAttackAchievement_SendResultList(Integer Duration);
/*!

*/
	const	CServerAdmin ServerAdmin;
/*!

*/
			Void AutoTeamBalance();
/*!

*/
			Void Solo_SetNewRecord(CScore PlayerScore,CMode::EMedal PlayerScore);
/*!

*/
	const	Boolean Solo_NewRecordSequenceInProgress;
/*!

*/
	const	CXmlRpc XmlRpc;
/*!

*/
	const	CParsingManager Xml;
/*!

*/
	const	CHttpManager Http;
/*!
Only available for local solo modes.
*/
	const	CInputManager Input;
/*!
Only available for local solo modes.
*/
	const	CDataFileMgr DataFileMgr;
/*!

*/
	const	CScoreMgr ScoreMgr;
/*!

*/
	const	CSystemPlatform System;
/*!

*/
	const	CUserV2Manager UserMgr;
/*!

*/
			Integer Synchro_AddBarrier();
/*!

*/
			Boolean Synchro_BarrierReached(Integer Barrier);
/*!

*/
			Boolean Users_AreAllies(CUser User1,CUser User2);
/*!

*/
			Void Users_RequestSwitchToSpectator(CUser User);
/*!

*/
			CUser Users_CreateFake(Text NickName,Integer RequestedTeam);
/*!

*/
			Void Users_DestroyFake(CUser User);
/*!

*/
			Void Users_SetNbFakeUsers(Integer NbTeam1,Integer NbTeam2);
/*!

*/
			Void Users_DestroyAllFakes();
/*!

*/
			Void ItemList_Begin();
/*!

*/
			Boolean ItemList_Begin();
/*!

*/
			Ident ItemList_Add(Text ModelName);
/*!
SkinNameOrUrl: can be 'Skins/Model/....', 'http://....', 'Default' (or '') for item default skin, 'Profile' for the user choice for the model. ModelName: 'DefaultPlayerModel' for the default map model, or the item filename.
*/
			Ident ItemList_AddWithSkin(Text ModelName,Text SkinNameOrUrl);
/*!

*/
			Void ItemList_End();
/*!

*/
			Void DemoToken_StartUsingToken();
/*!

*/
			Void DemoToken_StopUsingToken();
/*!

*/
			Void DemoToken_GetAndUseToken(CUser User);
/*!

*/
			Void ActionList_Begin();
/*!

*/
			Boolean ActionList_Begin();
/*!

*/
			Ident ActionList_Add(Text ActionName);
/*!

*/
			Void ActionList_End();
/*!

*/
			Boolean UseMinimap;
/*!

*/
			Boolean Replay_AutoStart;
/*!

*/
			Void Replay_Start();
/*!

*/
			Void Replay_Stop();
/*!

*/
	const	CAchievementsManager AchievementsManager;
/*!

*/
	const	CModeTurretManager TurretsManager;
/*!

*/
	const	CModeVehicleManager VehiclesManager;
/*!

*/
	const	CActionManager ActionsManager;
/*!

*/
			Void GameScene_ResetAll();
/*!

*/
			Text Dbg_DumpDeclareForVariables(CNod Nod,Boolean StatsOnly);
/*!

*/
	const	Integer UiUpdatePeriod;
};

/*!
* \brief A Shootmania player.
*
* Supported declare modes :
* - Local
* - NetworkRead
* - NetworkWrite
*/
class CSmPlayer : public CPlayer {
public :
	/*!
	
	*/
	enum ESpawnStatus {
		NotSpawned,
		Spawning,
		Spawned,
	};
/*!

*/
	const	CSmScore Score;
/*!

*/
	const	CSmPlayer::ESpawnStatus SpawnStatus;
/*!

*/
	const	Integer StartTime;
/*!

*/
			Integer EndTime;
/*!

*/
	const	Array<Integer> RaceWaypointTimes;
/*!

*/
	const	Array<Integer> LapWaypointTimes;
/*!

*/
	const	Integer CurrentLapNumber;
/*!

*/
	const	Integer LapStartTime;
/*!
Values in range (0.000000-10.000000)
*/
			Real AmmoGain;
/*!
Values in range (0.100000-10.000000)
*/
			Real AmmoPower;
/*!

*/
	const	Boolean AutoSwitchWeapon;
/*!

*/
	const	Integer CurWeapon;
/*!

*/
	const	Integer CurAmmo;
/*!

*/
	const	Integer CurAmmoMax;
/*!

*/
	const	Integer CurAmmoUnit;
/*!

*/
			Integer Armor;
/*!

*/
			Integer ArmorMax;
/*!

*/
			Integer ArmorGain;
/*!

*/
			Integer ArmorReplenishGain;
/*!
Values in range (0.100000-10.000000)
*/
			Real ArmorPower;
/*!

*/
			Integer Stamina;
/*!

*/
	const	Integer StaminaMaxValue;
/*!
Values in range (0.100000-3.000000)
*/
			Real StaminaMax;
/*!
Values in range (0.000000-1.000000)
*/
			Real StaminaGain;
/*!
Values in range (0.100000-1.000000)
*/
			Real StaminaPower;
/*!
Values in range (0.100000-1.000000)
*/
			Real SpeedPower;
/*!
Values in range (0.100000-1.000000)
*/
			Real JumpPower;
/*!

*/
			Boolean AllowWallJump;
/*!

*/
			Boolean AllowProgressiveJump;
/*!

*/
			Boolean UseAlternateWeaponVisual;
/*!

*/
			Boolean IsHighlighted;
/*!
Values in range (0.000000-1.000000)
*/
			Real EnergyLevel;
/*!

*/
			Vec3 ForceColor;
/*!
5 ascii chars (ex: '01TMN') or empty for default value 
*/
			Text Dossard;
/*!
Values in range (0.000000-1.000000)
*/
	const	Real GetLinearHue;
/*!

*/
			Real ForceLinearHue;
/*!

*/
			Ident ForceModelId;
/*!

*/
			Boolean HasShield;
/*!

*/
	const	Boolean IsInVehicle;
/*!

*/
			Boolean IsStuck;
/*!
Values in range (0.000000-500.000000)
*/
			Real ThrowSpeed;
/*!

*/
	const	Integer CurrentClan;
/*!

*/
	const	Integer IdleDuration;
/*!

*/
	const	Boolean IsEntityStateAvailable;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Real AimYaw;
/*!

*/
	const	Real AimPitch;
/*!

*/
	const	Vec3 AimDirection;
/*!

*/
	const	Vec3 Velocity;
/*!

*/
	const	Real Speed;
/*!

*/
	const	Boolean IsUnderground;
/*!

*/
	const	Boolean IsTouchingGround;
/*!

*/
	const	Boolean IsInAir;
/*!

*/
	const	Boolean IsInWater;
/*!

*/
	const	Boolean IsInOffZone;
/*!

*/
	const	Boolean IsOnTech;
/*!

*/
	const	Boolean IsOnTechGround;
/*!

*/
	const	Boolean IsOnTechLaser;
/*!

*/
	const	Boolean IsOnTechArrow;
/*!

*/
	const	Boolean IsOnTechNucleus;
/*!

*/
	const	Boolean IsOnTechArmor;
/*!

*/
	const	Boolean IsOnTechSafeZone;
/*!

*/
	const	Boolean IsOnTechTeleport;
/*!

*/
	const	Boolean IsOnTechNoWeapon;
/*!

*/
	const	Boolean IsPowerJumpActivable;
/*!

*/
	const	Boolean IsTeleportActivable;
/*!

*/
	const	Boolean IsAttractorActivable;
/*!

*/
	const	Integer NbActiveAttractors;
/*!

*/
	const	Boolean IsCapturing;
/*!

*/
	const	CSmMapLandmark CapturedLandmark;
/*!

*/
	const	Array<CSmObject> Objects;
/*!

*/
	const	CModeVehicle Vehicle;
/*!

*/
	const	Boolean IsFakePlayer;
/*!

*/
	const	Boolean IsBot;
/*!

*/
			Boolean UseDelayedVisuals;
/*!

*/
			Boolean TrustClientSimu;
/*!

*/
	const	CSmPlayerDriver Driver;
/*!

*/
			Real AccelCoef;
/*!

*/
			Real ControlCoef;
/*!

*/
			Real GravityCoef;
/*!

*/
			Real AdherenceCoef;
/*!

*/
	const	Real Upwardness;
/*!

*/
	const	Real Distance;
/*!

*/
	const	Integer DisplaySpeed;
/*!

*/
	const	Real InputSteer;
/*!

*/
	const	Real InputGasPedal;
/*!

*/
	const	Boolean InputIsBraking;
/*!

*/
	const	Real EngineRpm;
/*!

*/
	const	Integer EngineCurGear;
/*!

*/
	const	Real EngineTurboRatio;
/*!

*/
	const	Integer WheelsContactCount;
/*!

*/
	const	Integer WheelsSkiddingCount;
/*!

*/
	const	Integer FlyingDuration;
/*!

*/
	const	Integer SkiddingDuration;
/*!

*/
	const	Real SkiddingDistance;
/*!

*/
	const	Real FlyingDistance;
/*!

*/
	const	Integer HandicapNoGasDuration;
/*!

*/
	const	Integer HandicapForceGasDuration;
/*!

*/
	const	Integer HandicapNoBrakesDuration;
/*!

*/
	const	Integer HandicapNoSteeringDuration;
/*!

*/
	const	Integer HandicapNoGripDuration;
};

/*!
* \brief Event recieved by ShootMania gamemodes.
*
* Supported declare modes :
* - Local
*/
class CSmModeEvent : public CBaseEvent {
public :
	/*!
	
	*/
	enum EType {
		Unknown,
		OnShoot,
		OnHit,
		OnNearMiss,
		OnArmorEmpty,
		OnCapture,
		OnShotDeny,
		OnFallDamage,
		OnCommand,
		OnPlayerAdded,
		OnPlayerRemoved,
		OnPlayerRequestRespawn,
		OnActionCustomEvent,
		OnActionEvent,
		OnPlayerTouchesObject,
		OnPlayerThrowsObject,
		OnPlayerTriggersSector,
		OnPlayerTriggersWaypoint,
		OnPlayerRequestActionChange,
		OnVehicleArmorEmpty,
		OnVehicleCollision,
		OnVehicleVsVehicleCollision,
	};
	/*!
	
	*/
	enum EActionSlot {
		Slot_A,
		Slot_B,
		Slot_C,
		Slot_D,
		Slot_E,
		Slot_F,
		Slot_G,
		Slot_H,
	};
	/*!
	
	*/
	enum EActionInput {
		Weapon,
		Secondary,
		Movement,
		Activable1,
		Activable2,
		Activable3,
		Activable4,
		Activable5,
		Activable6,
		Activable7,
		Activable8,
		Activable9,
		Activable0,
		Consumable1,
		Consumable2,
		None,
	};
/*!

*/
	const	CSmModeEvent::EType Type;
/*!

*/
	const	CSmPlayer Player;
/*!

*/
			Integer Damage;
/*!

*/
	const	Integer VictimShield;
/*!

*/
	const	CEntity VictimEntity;
/*!

*/
			Integer ShooterPoints;
/*!

*/
	const	CEntity ShooterEntity;
/*!

*/
	const	Integer ShooterClan;
/*!

*/
	const	Real Height;
/*!

*/
	const	Real MissDist;
/*!

*/
	const	Integer WeaponNum;
/*!

*/
	const	Boolean ShooterUsedAction;
/*!

*/
	const	Integer ShooterWeaponNum;
/*!

*/
	const	CSmModeEvent::EActionSlot ShooterActionSlot;
/*!

*/
	const	Text ShooterActionId;
/*!

*/
	const	Boolean VictimUsedAction;
/*!

*/
	const	Integer VictimWeaponNum;
/*!

*/
	const	CSmModeEvent::EActionSlot VictimActionSlot;
/*!

*/
	const	Text VictimActionId;
/*!

*/
	const	CSmModeEvent::EActionSlot ActionSlot;
/*!

*/
	const	CSmModeEvent::EActionInput ActionInput;
/*!

*/
	const	Text ActionId;
/*!

*/
	const	Text Param1;
/*!

*/
	const	Array<Text> Param2;
/*!

*/
	const	CSmObject Object;
/*!

*/
	const	Integer WaypointTime;
/*!

*/
	const	Integer WaypointLapTime;
/*!

*/
	const	Boolean IsFinish;
/*!

*/
	const	Boolean IsNewLap;
/*!

*/
	const	CSmMapLandmark Landmark;
/*!

*/
	const	CUser User;
/*!

*/
	const	Boolean PlayerWasSpawned;
/*!

*/
	const	Boolean PlayerWasDisconnected;
/*!

*/
	const	Boolean PlayerWasInLadderMatch;
/*!

*/
	const	Vec3 PlayerLastPosition;
/*!

*/
	const	Vec3 PlayerLastAimDirection;
/*!

*/
	const	Boolean GiveUp;
/*!

*/
	const	Boolean RegressRespawn;
/*!

*/
	const	Text CommandName;
/*!

*/
	const	Boolean CommandValueBoolean;
/*!

*/
	const	Integer CommandValueInteger;
/*!

*/
	const	Real CommandValueReal;
/*!

*/
	const	Text CommandValueText;
/*!

*/
	const	Vec2 CommandValueVec2;
/*!

*/
	const	Vec3 CommandValueVec3;
/*!

*/
	const	Int2 CommandValueInt2;
/*!

*/
	const	Int3 CommandValueInt3;
/*!

*/
	const	Integer ActionChange;
};

/*!
* \brief Documentation for class CSmMapBase
*/
class CSmMapBase : public CNod {
public :
/*!

*/
			Integer Clan;
/*!

*/
			Boolean IsActive;
/*!

*/
	const	Integer NumberOfCollectors;
};

/*!
* \brief Documentation for class CSmMapLandmark
*
* Supported declare modes :
* - Local
* - Metadata
*/
class CSmMapLandmark : public CMapLandmark {
public :
/*!

*/
	const	CSmMapBase Base;
/*!

*/
	const	CSmMapGate Gate;
/*!

*/
	const	CSmMapGauge Gauge;
};

/*!
* \brief Scoring info for ShootMania players.
*
* Supported declare modes :
* - Local
* - NetworkRead
* - NetworkWrite
*/
class CSmScore : public CScore {
public :
/*!

*/
	const	Integer TeamNum;
/*!

*/
			Integer Points;
/*!

*/
			Integer RoundPoints;
/*!

*/
			Integer NbRespawnsRequested;
/*!

*/
	const	Integer NbEliminationsInflicted;
/*!

*/
	const	Integer NbEliminationsTaken;
/*!

*/
	const	Integer DamageInflicted;
/*!

*/
	const	Integer DamageTaken;
/*!

*/
	const	Array<Integer> BestRaceTimes;
/*!

*/
	const	Array<Integer> PrevRaceTimes;
/*!

*/
	const	Array<Integer> BestLapTimes;
/*!

*/
	const	Array<Integer> PrevLapTimes;
};

/*!
* \brief Documentation for class CMapSpawn
*/
class CMapSpawn : public CNod {
public :
};

/*!
* \brief Documentation for class CModeTurret
*
* Supported declare modes :
* - Local
*/
class CModeTurret : public CEntity {
public :
/*!

*/
			Integer Armor;
/*!

*/
			Integer ArmorMax;
/*!

*/
	const	CPlayer Owner;
};

/*!
* \brief Documentation for class CModeVehicle
*
* Supported declare modes :
* - Local
*/
class CModeVehicle : public CEntity {
public :
/*!

*/
			Integer Armor;
/*!

*/
			Integer ArmorMax;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Real Pitch;
/*!

*/
	const	Real Roll;
/*!

*/
	const	Vec3 Left;
/*!

*/
	const	Vec3 Up;
/*!

*/
	const	Vec3 Dir;
/*!

*/
	const	Vec3 Velocity;
/*!

*/
			Integer Clan;
/*!

*/
			Real AccelCoef;
/*!

*/
	const	Real AccelInput;
/*!

*/
			Void SetEngineActivated(Boolean IsActivated);
};

/*!
* \brief Documentation for class CMapBotPath
*/
class CMapBotPath : public CNod {
public :
/*!

*/
	const	Integer Clan;
/*!

*/
	const	Array<Vec3> Path;
/*!

*/
	const	Boolean IsFlying;
/*!

*/
	const	Ident BotModelId;
};

/*!
* \brief Documentation for class CMapBotSpawn
*/
class CMapBotSpawn : public CNod {
public :
/*!

*/
	const	Boolean IsFlying;
/*!

*/
	const	Ident BotModelId;
};

/*!
* \brief Documentation for class CEntity
*/
class CEntity : public CNod {
public :
/*!
Use this instead of Id when filling CUIConfig.MarkersXML
*/
	const	Ident MarkerId;
};

/*!
* \brief Documentation for class CMapWaypoint
*/
class CMapWaypoint : public CNod {
public :
/*!

*/
	const	Boolean IsFinish;
/*!

*/
	const	Boolean IsMultiLap;
};

/*!
* \brief An instance of an object.
*
* Supported declare modes :
* - Local
*/
class CSmObject : public CEntity {
public :
	/*!
	
	*/
	enum EStatus {
		OnPlayer,
		OnAnchor,
		InWorld,
		Unspawned,
	};
/*!

*/
	const	CSmObject::EStatus Status;
/*!

*/
	const	Ident ModelId;
/*!

*/
			Void SetAnchor(CMapObjectAnchor ObjectAnchor);
/*!

*/
			Void SetPlayer(CSmPlayer Player);
/*!

*/
			Void SetPosition(Vec3 Position);
/*!

*/
			Void SetPositionAndVel(Vec3 Position,Vec3 Vel);
/*!

*/
			Void SetUnspawned();
/*!
Player holding the object, or Null if the object isn't held by a player.
*/
	const	CSmPlayer Player;
/*!

*/
	const	CSmMapLandmark AnchorLandmark;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Vec3 Vel;
/*!

*/
			Integer MachineState;
/*!

*/
			Boolean Throwable;
/*!

*/
	const	Ident ThrowLatestPlayerId;
};

/*!
* \brief The ghosts manager.
*/
class CGhostManager : public CNod {
public :
/*!

*/
			Ident Ghost_Add(CGhost Ghost);
/*!

*/
			Ident Ghost_Add(CGhost Ghost,Boolean IsGhostLayer);
/*!

*/
			Ident Ghost_Add(CGhost Ghost,Boolean IsGhostLayer,Integer TimeOffset);
/*!

*/
			Ident Ghost_AddWaypointSynced(CGhost Ghost,Boolean IsGhostLayer);
/*!

*/
			Boolean Ghost_IsReplayOver(Ident GhostInstanceId);
/*!

*/
			Boolean Ghost_IsVisible(Ident GhostInstanceId);
/*!

*/
			Void Ghost_Remove(Ident GhostInstanceId);
/*!

*/
			Void Ghost_RemoveAll();
/*!
5 ascii chars (ex: '01TMN') or empty for default value 
*/
			Void Ghost_SetDossard(Ident GhostInstanceId,Text Dossard);
};

/*!
* \brief A ghost model.
*/
class CGhost : public CNod {
public :
/*!
Ghost id
*/
	const	Ident Id;
/*!
Result associated to this ghost (score/time/respawncount).
*/
	const	CTmRaceResultNod Result;
/*!
Nickname of the player.
*/
			Text Nickname;
/*!
Trigram of the player.
*/
			Text Trigram;
/*!

*/
	const	Text CountryPath;
};

/*!
* \brief Documentation for class CAction
*/
class CAction : public CNod {
public :
};

/*!
* \brief An action event
*
* Supported declare modes :
* - Local
*/
class CSmActionEvent : public CBaseConstEvent {
public :
	/*!
	
	*/
	enum EType {
		OnHitPlayer,
		OnProjectileEnd,
		OnProjectileDestroyed,
		OnHitObject,
		OnHitShield,
		OnHitVehicle,
		OnShieldEnd,
		OnHitTurret,
		OnInputChange,
		OnFocusedScroll,
	};
	/*!
	
	*/
	enum EInputChange {
		IsActive,
		Focused_Main,
		Focused_Secondary,
		Focused_Activable1,
		Focused_Activable2,
		Focused_Activable3,
		Focused_Activable4,
		Focused_Activable5,
		Focused_Activable6,
		Focused_Activable7,
		Focused_Activable8,
		Focused_Activable9,
		Focused_Activable0,
		Focused_Consumable1,
		Focused_Consumable2,
	};
/*!
Type.
*/
	const	CSmActionEvent::EType Type;
/*!

*/
	const	Ident ProjectileModelId;
/*!

*/
	const	Integer ProjectileStartDate;
/*!

*/
	const	Integer Damage;
/*!

*/
	const	Integer ContextId;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	Vec3 Direction;
/*!

*/
	const	Vec3 Normal;
/*!

*/
	const	CEntity Victim;
/*!

*/
	const	Integer Shield;
/*!

*/
	const	CSmActionEvent::EInputChange Input;
/*!

*/
	const	Integer ScrollDelta;
};

/*!
* \brief API for the plugins of the map editor.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CMapType : public CMapEditorPlugin {
public :
	/*!
	
	*/
	enum ValidationStatus {
		NotValidable,
		Validable,
		Validated,
	};
/*!

*/
			Boolean CustomEditAnchorData;
/*!

*/
			Void ClearMapMetadata();
/*!

*/
			CMapType::ValidationStatus ValidationStatus;
/*!

*/
			Text ValidabilityRequirementsMessage;
/*!

*/
			Boolean ValidationEndRequested;
/*!

*/
			Boolean ValidationEndNoConfirm;
/*!

*/
			Void RequestEnterPlayground();
/*!

*/
			Void RequestLeavePlayground();
/*!

*/
	const	Boolean IsSwitchedToPlayground;
/*!

*/
	const	CUIConfigMgr UIManager;
/*!

*/
	const	Array<CUser> Users;
};

/*!
* \brief Audio device settings.
*/
class CAudioSettings : public CNod {
public :
/*!

*/
			Integer DirtyCounter;
/*!

*/
			Array<Text> Devices;
/*!

*/
			Text Device_Current;
/*!

*/
			Text Device_NextApply;
};

/*!
* \brief Documentation for class CModulePlayground
*/
class CModulePlayground : public CNod {
public :
/*!

*/
			Void Hide();
/*!

*/
			Void Hide(CUIConfig UIConfig);
/*!

*/
			Void Show();
/*!

*/
			Void Show(CUIConfig UIConfig);
/*!

*/
			Boolean IsVisible(CUIConfig UIConfig);
};

/*!
* \brief Documentation for class CModuleMenuComponent
*/
class CModuleMenuComponent : public CNod {
public :
/*!

*/
	const	CUILayer ComponentLayer;
/*!

*/
			Void Hide();
/*!

*/
			Void Show();
};

/*!
* \brief Documentation for class CModuleMenuPage
*/
class CModuleMenuPage : public CNod {
public :
/*!

*/
	const	Text Name;
/*!

*/
	const	Array<CModuleMenuComponent> Components;
};

/*!
* \brief This is the title menus Manialink interface.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CModuleMenuLayer : public CManiaAppTitleLayer {
public :
/*!

*/
	const	Array<CModuleMenuComponent> Components;
/*!

*/
			CModuleMenuComponent GetFirstComponent(Text Name);
};

/*!
* \brief API for titles menus to control the main loop.
*/
class CTitleControl : public CNod {
public :
	/*!
	
	*/
	enum ESplitScreenLayout {
		Horizontal,
		Vertical,
		Four,
	};
	/*!
	
	*/
	enum EResult {
		Success,
		Error_Internal,
		Error_DataMgr,
		Error_Net_ServerNotFound,
		Error_Net_ServerUnreachable,
		Error_Net_Disconnected,
		Error_Net_WrongPassword,
		Error_Network_OnlineExpired,
		Error_Network_ServerFull,
		Error_Abort,
	};
	/*!
	
	*/
	enum EEditorType {
		ActionMaker,
		ChallengeEditor,
		ItemEditor,
		InterfaceDesigner,
		MeshModeler,
		ModuleStudio,
		PixelArt,
		EditorEditor,
		VehicleAssembler,
		MaterialEditor,
	};
	/*!
	
	*/
	enum EReplayEditType {
		None,
		Edit,
		View,
		Shoot,
	};
/*!
Can a command be issued.
*/
	const	Boolean IsReady;
/*!
Result of the latest command issued.
*/
	const	CTitleControl::EResult LatestResult;
/*!

*/
	const	Text CustomResultType;
/*!

*/
	const	Array<Text> CustomResultData;
/*!

*/
			Void PlayMap(Text Map,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayCampaign(CCampaign Campaign,CMapInfo MapInfo,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMapList(Array<Text> MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMatchSettings(CMatchSettings MatchSettings,Text OverrideMode,Text OverrideSettingsXml);
/*!

*/
			Void PlayAgainstReplay(Text Replay,Text Mode,Text SettingsXml);
/*!

*/
			Void PlaySplitScreen(CTitleControl::ESplitScreenLayout LayoutType,Array<Text> MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlayMultiOnSameScreen(Array<Text> MapList,Text Mode,Text SettingsXml);
/*!

*/
			Void PlaySplitScreen(CTitleControl::ESplitScreenLayout LayoutType,CMatchSettings MatchSettings);
/*!

*/
			Void PlayMultiOnSameScreen(CMatchSettings MatchSettings);
/*!

*/
			Void ViewReplay(Text Replay);
/*!

*/
			Void OpenEditor(Text EditorName,Text MainPluginSettings);
/*!

*/
			Void OpenEditor(CTitleControl::EEditorType EditorType);
/*!

*/
			Void EditSkins();
/*!

*/
			Void EditSkinsFromFileName(Text SkinFilePath);
/*!

*/
			Void EditReplay(Array<Text> ReplayList);
/*!

*/
			Void EditReplay(Array<Text> ReplayList,CTitleControl::EReplayEditType EditType);
/*!

*/
			Void EditGhosts(Text Map);
/*!

*/
			Void EditAsset(Text EditorName,Text MainPluginSettingsXml,Text RelativeFileName);
/*!

*/
			Void EditMap(Text Map,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditMap(Text Map,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditMap(Text Map,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text EditorPluginScript,Text EditorPluginArgument,Boolean UpgradeToAdvancedEditor);
/*!

*/
			Void EditMap(Text Map,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Array<Text> EditorPluginsScripts,Array<Text> EditorPluginsArguments,Boolean UpgradeToAdvancedEditor);
/*!

*/
			Void EditNewMap(Text Environment,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text MapType,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditNewMap(Text Environment,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text MapType,Boolean UseSimpleEditor,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditNewMap(Text Environment,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text MapType,Boolean UseSimpleEditor,Array<Text> EditorPluginsScripts,Array<Text> EditorPluginsArguments);
/*!

*/
			Void EditNewMapFromBaseMap(Text BaseMapName,Text ModNameOrUrl,Text PlayerModel,Text MapType,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditNewMapFromBaseMap(Text BaseMapName,Text Decoration,Text ModNameOrUrl,Text PlayerModel,Text MapType,Text EditorPluginScript,Text EditorPluginArgument);
/*!

*/
			Void EditBadges();
/*!

*/
	const	Boolean CanPublishFiles;
/*!
Set FileName='' to open a file select dialog.
*/
			Void PublishFile(Text FileName);
/*!

*/
			Void ProcessManiaCodeXml(Text ManiaCodeXml);
/*!

*/
	const	Array<CServerInfo> LocalServers;
/*!

*/
	const	Array<CServerInfo> LocalServers_CurrentTitle;
/*!

*/
			Void DiscoverLocalServers();
/*!

*/
			Void CreateServer(Text ServerName,Text ServerComment,Integer MaxPlayerCount,Text Password,CMatchSettings MatchSettings,Text PasswordSpectators);
/*!

*/
			Void CreateServer(Text ServerName,Text ServerComment,Integer MaxPlayerCount,Text Password,Text PasswordSpectators,CMatchSettings MatchSettings,Boolean LocalOnly);
/*!
Fetch the server info, from the account id, or 'IP:xxx.xxx.xxx.xxx' with LAN ip
*/
			Void GetServerInfo(Text ServerLogin);
/*!

*/
			Void GetServerInfo(CServerInfo LocalServer);
/*!

*/
			Void GetServerInfo_Abort();
/*!

*/
	const	CServerInfo GetServerInfo_Result;
/*!

*/
			Void Join_GetServerInfo_Result(Boolean AsSpectator,Text Password);
/*!
Join a server
*/
			Void JoinServer(Text ServerLogin,Boolean AsSpectator,Text Password);
/*!

*/
			Void Quit();
};

/*!
* \brief Station mania app.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaAppStation : public CManiaAppBase {
public :
/*!

*/
	const	CStation Station;
/*!

*/
			Void EnterStation();
/*!

*/
			Void Maker_EditTitle(Text EditedTitleId);
/*!
A new title id will be derived from the EditedTitleName.
*/
			Void Maker_EditNewTitle(Text EditedTitleName);
/*!

*/
	const	Array<CPackCreatorTitleInfo> Maker_EditedTitles;
};

/*!
* \brief Station info & manipulation.
*/
class CStation : public CNod {
public :
	/*!
	
	*/
	enum EEchelon {
		None,
		Bronze1,
		Bronze2,
		Bronze3,
		Silver1,
		Silver2,
		Silver3,
		Gold1,
		Gold2,
		Gold3,
	};
/*!

*/
	const	CTitle Title;
/*!

*/
	const	Integer AudienceRegisteredUsers;
/*!

*/
	const	Integer CampaignMedalsMax;
/*!

*/
	const	Integer CampaignMedalsCurrent;
/*!

*/
	const	Integer CampaignMedalsRanking;
/*!

*/
	const	Real LadderPoints;
/*!

*/
	const	Integer LadderRank;
/*!

*/
	const	CStation::EEchelon Echelon;
/*!

*/
	const	Integer NextEchelonPercent;
/*!

*/
			Boolean DisableQuickEnter;
/*!

*/
			Boolean IsLogoVisible;
/*!

*/
			Real GhostAlpha;
/*!

*/
			Vec3 FocusLightColor;
/*!

*/
			Vec3 NormalLightColor;
/*!
Is title present in WorkTitles folder?
*/
	const	Boolean IsEditable;
};

/*!
* \brief Ingame Manialink API for ShootMania.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CSmMlScriptIngame : public CMlScriptIngame {
public :
/*!

*/
	const	Integer ArenaNow;
/*!
Player receiving the inputs. Null if spectating other players.
*/
	const	CSmPlayer InputPlayer;
/*!
Player currently targetted by the camera. Same as InputPlayer when playing. Can be null in freecam when there's no specific target.
*/
	const	CSmPlayer GUIPlayer;
/*!

*/
	const	Array<CSmPlayer> Players;
/*!

*/
	const	Array<CModeVehicle> Vehicles;
/*!

*/
	const	Array<CSmScore> Scores;
/*!

*/
	const	Array<Integer> ClanScores;
/*!

*/
			Boolean HideResumePlayingButton;
/*!

*/
	const	Array<CSmMapBase> MapBases;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_PlayerSpawn;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Gauge;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Sector;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_BotPath;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_BotSpawn;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_ObjectAnchor;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Gate;
/*!

*/
	const	Array<CSmMapLandmark> MapLandmarks_Foundation;
};

/*!
* \brief API for plugins to get playground info.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CPlaygroundClient : public CNod {
public :
	/*!
	
	*/
	enum ESpectatorCameraType {
		Replay,
		Follow,
		Free,
		StandardCount,
		NotUsed0,
		NotUsed1,
		NotUsed2,
		NotUsed3,
		NotUsed4,
		NotUsed5,
		NotUsed6,
		NotUsed7,
		NotUsed8,
		NotUsed9,
		FollowForced,
		DontChange,
	};
	/*!
	
	*/
	enum ESpectatorTargetType {
		None,
		Single,
		AllPlayers,
		AllMap,
	};
/*!
Null when no map loaded.
*/
	const	CMap Map;
/*!

*/
	const	Integer GameTime;
/*!

*/
	const	CUser LocalUser;
/*!

*/
	const	CUIConfig UI;
/*!

*/
	const	CServerInfo ServerInfo;
/*!

*/
	const	Ident SettingsPlayerModelId;
/*!
Is in spectator mode - may be only for a short time between rounds.
*/
	const	Boolean IsSpectator;
/*!
Client actually desires to spectate instead of playing.
*/
	const	Boolean IsSpectatorClient;
/*!

*/
	const	Boolean UseClans;
/*!

*/
	const	Boolean UseForcedClans;
/*!

*/
	const	Boolean IsLoadingScreen;
/*!

*/
	const	Boolean IsServerOrSolo;
/*!

*/
			Void QuitServer(Boolean Silent);
/*!

*/
			Void QuitServerAndSetResult(Boolean Silent,Text Type,Array<Text> Data);
/*!

*/
	const	Boolean IsInGameMenuDisplayed;
/*!

*/
			Void JoinTeam1();
/*!

*/
			Void JoinTeam2();
/*!

*/
	const	Array<CTeam> Teams;
/*!
Request change of IsSpectatorClient (not immediate, and it may be refused). Caveat: will not set Request_Success
*/
			Void RequestSpectatorClient(Boolean Spectator);
/*!

*/
			Void SetSpectateTarget(Text Player);
/*!

*/
			Void ShowProfile(Text Player);
/*!
Save the current replay to a file. Filename is optional.
*/
			Boolean SaveReplay(Text FileName);
/*!

*/
			Boolean SavePrevReplay(Text FileName);
/*!
Save the current map to a file (if the server IsMapDownloadAllowed). Filename is optional.
*/
			Boolean SaveMap(Text FileName);
/*!

*/
			Void MapList_Request();
/*!

*/
			CPlaygroundClient::ESpectatorCameraType GetSpectatorCameraType();
/*!

*/
			CPlaygroundClient::ESpectatorTargetType GetSpectatorTargetType();
/*!

*/
			Void SetWantedSpectatorCameraType(CPlaygroundClient::ESpectatorCameraType CameraType);
/*!

*/
	const	Boolean MapList_IsInProgress;
/*!

*/
	const	Array<Text> MapList_Names;
/*!

*/
	const	Array<Text> MapList_MapUids;
/*!

*/
	const	Boolean Request_IsInProgress;
/*!

*/
	const	Boolean Request_Success;
/*!

*/
			Void RequestRestartMap();
/*!

*/
			Void RequestNextMap();
/*!

*/
			Void RequestGotoMap(Text MapUid);
/*!

*/
			Void RequestSetNextMap(Text MapUid);
/*!

*/
			Void RequestAutoTeamBalance();
/*!
Change some settings from the mode with new values. No need to include unchanged settings.  ex: '<script_settings><setting name="S_TimeLimit" type="integer" value="300"/><script_settings/>'
nb: you can use TriggerPageAction('maniaplanet:editsettings'); to use the legacy UI.
*/
			Void RequestChangeModeScriptSettings(Text SettingsXml);
/*!

*/
			Boolean DisablePlayingStateTracking;
};

/*!
* \brief API for game interface client scripts
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaAppPlaygroundCommon : public CManiaApp {
public :
/*!

*/
	const	Array<CManiaAppPlaygroundEvent> PendingEvents;
/*!

*/
	const	CPlaygroundClient Playground;
/*!

*/
	const	CMap Map;
/*!

*/
	const	CGhostManager GhostMgr;
/*!
(read-only) UI actually displayed, as defined by the server.
*/
			CUIConfig UI;
/*!
Locally accessible by the client script to locally override settings from the server.
*/
			CUIConfig ClientUI;
/*!

*/
	const	Integer SplitScreenCount;
/*!
Set a layer to be displayed on a subscreen. ScreenNum: 0=global, 1,2.... = screen index.  Limitation: a local layer can only be one screen at a time.
*/
			Void SplitScreenAssignLayer(CUILayer UILayer,Integer ScreenNum);
};

/*!
* \brief Documentation for class CMap
*
* Supported declare modes :
* - Local
* - Metadata
* - Persistent
*/
class CMap : public CNod {
public :
/*!

*/
	const	CMapInfo MapInfo;
/*!

*/
			Text MapName;
/*!

*/
			Text Comments;
/*!

*/
	const	Text AuthorZoneIconUrl;
/*!

*/
	const	Text CollectionName;
/*!

*/
	const	Text DecorationName;
/*!

*/
	const	Text AuthorLogin;
/*!

*/
	const	Text AuthorNickName;
/*!

*/
	const	Text AuthorZonePath;
/*!

*/
	const	Text MapType;
/*!

*/
	const	Text MapStyle;
/*!

*/
			Integer TMObjective_AuthorTime;
/*!

*/
			Integer TMObjective_GoldTime;
/*!

*/
			Integer TMObjective_SilverTime;
/*!

*/
			Integer TMObjective_BronzeTime;
/*!

*/
			Integer TMObjective_NbLaps;
/*!

*/
			Boolean TMObjective_IsLapRace;
/*!

*/
			Text ObjectiveTextAuthor;
/*!

*/
			Text ObjectiveTextGold;
/*!

*/
			Text ObjectiveTextSilver;
/*!

*/
			Text ObjectiveTextBronze;
/*!

*/
	const	Integer CopperPrice;
/*!

*/
	const	Int3 Size;
/*!

*/
	const	Boolean HasCustomIntro;
/*!

*/
	const	Boolean HasCustomMusic;
};

/*!
* \brief Manager of achievements.
*/
class CAchievementsManager : public CNod {
public :
/*!
List of events for current frame.
*/
	const	Array<CAchievementsEvent> PendingEvents;
/*!
Achievements descriptions.
*/
	const	Array<CAchievementsAchievement> Achievements;
/*!
Stats descriptions.
*/
	const	Array<CAchievementsStat> Stats;
/*!
Achievements descriptions.
*/
	const	Array<CAchievementsAchievementDesc> AchievementDescriptions;
/*!
Stats descriptions.
*/
	const	Array<CAchievementsStatDesc> StatDescriptions;
/*!

*/
			Void SendEvent(Ident UserId,Text Mnemo,Array<Integer> Params);
};

/*!
* \brief API for Maniaplanet client scripts.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaAppBrowser : public CManiaApp {
public :
/*!

*/
	const	Array<CManiaAppEvent> PendingEvents;
/*!

*/
			Void BrowserBack();
/*!

*/
			Void BrowserQuit();
/*!

*/
			Void BrowserHome();
/*!

*/
			Void BrowserReload();
/*!

*/
			Text BrowserFocusedFrameId;
};

/*!
* \brief Documentation for class CMlFrame
*
* Supported declare modes :
* - Local
*/
class CMlFrame : public CMlControl {
public :
/*!

*/
	const	Array<CMlControl> Controls;
/*!

*/
			CMlControl GetFirstChild(Text ControlId);
/*!

*/
			Boolean ScrollActive;
/*!

*/
			Vec2 ScrollOffset;
/*!

*/
	const	Vec2 ScrollAnimOffset;
/*!

*/
			Vec2 ScrollMax;
/*!

*/
			Vec2 ScrollMin;
/*!

*/
			Boolean ScrollGridSnap;
/*!

*/
			Vec2 ScrollGrid;
/*!

*/
			Void Scroll(Vec2 DeltaInGridUnits);
/*!

*/
			Void ScrollBumpTop();
/*!

*/
			Void ScrollBumpBottom();
/*!

*/
			Void ScrollBumpLeft();
/*!

*/
			Void ScrollBumpRight();
/*!

*/
			Boolean DisablePreload;
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CBaseConstEvent : public CNod {
public :
/*!
Use this flag to solve issues where some events are interpreted twice by different script librairies.<br/>Discard events if the flag is set. Set the flag after handling the event.
*/
			Boolean HasBeenProcessed;
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlColorPicker : public CMlControl {
public :
/*!

*/
			Vec3 Color;
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlTimeLine : public CMlControl {
public :
/*!

*/
			Real Time;
/*!

*/
			Real TimeMin;
/*!

*/
			Real TimeMax;
/*!

*/
			Integer Page;
/*!

*/
			Integer TracksPerPage;
/*!

*/
	const	Boolean IsDraggingCursor;
/*!

*/
	const	Boolean IsDraggingBlock;
/*!

*/
	const	Boolean IsDraggingKey;
/*!

*/
	const	Boolean IsScaling;
/*!

*/
	const	Boolean IsPanning;
/*!

*/
			Void ShowFullTimeLine();
/*!

*/
			Void ResetCycling();
/*!

*/
			Void SetSimpleMediaTrackerPilot(CEditorMediaTracker MediaTracker);
/*!

*/
			Void SetSelection(Integer Track,Integer Block,Integer Key);
/*!

*/
			Void SetSeparatorColor(Text HexColor);
/*!

*/
			Void SetBgColor(Text HexColor);
/*!

*/
			Void SetCursorColor(Text HexColor);
/*!

*/
			Void SetRulerColor(Text HexColor);
/*!

*/
			Void SetRulerLineColor(Text HexColor);
/*!

*/
			Void SetKeyColor(Text HexColor);
/*!

*/
			Void SetStartIsCycling(Real Time);
/*!

*/
			Void SetStopIsCycling(Real Time);
/*!

*/
			Void SetTimeLimit(Real TimeLimit);
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlSlider : public CMlControl {
public :
/*!

*/
			Real Value;
/*!

*/
			Real MinRange;
/*!

*/
			Real MaxRange;
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlMediaPlayer : public CMlControl {
public :
/*!

*/
			Boolean IsInitPlay;
/*!

*/
			Boolean Music;
/*!

*/
			Boolean IsLooping;
/*!

*/
			Real Volume;
/*!

*/
			Text Url;
/*!

*/
			Void Play();
/*!

*/
			Void Stop();
/*!

*/
			Void StopAndRewind();
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlGraph : public CMlControl {
public :
/*!

*/
			Vec2 CoordsMin;
/*!

*/
			Vec2 CoordsMax;
/*!

*/
			CMlGraphCurve AddCurve();
/*!

*/
			Void RemoveCurve(CMlGraphCurve Curve);
/*!

*/
			Array<CMlGraphCurve> Curves;
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlGauge : public CMlControl {
public :
/*!

*/
			Text Style;
/*!

*/
			Void SetRatio(Real NewRatio);
/*!

*/
			Void SetClan(Integer NewClan);
/*!
Values in range (0.000000-1.000000)
*/
			Real Ratio;
/*!
Values in range (0.000000-1.000000)
*/
			Real GradingRatio;
/*!

*/
			Integer Clan;
/*!

*/
			Vec3 Color;
/*!

*/
			Boolean DrawBackground;
/*!

*/
			Boolean DrawBlockBackground;
/*!

*/
			Boolean CenteredBar;
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlCamera : public CMlControl {
public :
};

/*!
* \brief Manialink entry.
*
* Supported declare modes :
* - Local
*/
class CMlTextEdit : public CMlControl {
public :
	/*!
	
	*/
	enum EControlScriptEditorTextFormat {
		Basic,
		Script,
		Password,
		Newpassword,
	};
/*!

*/
			Text Value;
/*!

*/
			Void StartEdition();
/*!

*/
			Integer MaxLine;
/*!

*/
			Boolean AutoNewLine;
/*!

*/
			Boolean ShowLineNumbers;
/*!

*/
			Real LineSpacing;
/*!

*/
	const	Integer ValueLineCount;
/*!

*/
			Real Opacity;
/*!

*/
			Vec3 TextColor;
/*!

*/
			Real TextSizeReal;
/*!

*/
			CMlTextEdit::EControlScriptEditorTextFormat TextFormat;
};

/*!
* \brief Manialink entry.
*
* Supported declare modes :
* - Local
*/
class CMlEntry : public CMlControl {
public :
	/*!
	
	*/
	enum ETextFormat {
		Basic,
		Script,
		Password,
		Newpassword,
	};
	/*!
	
	*/
	enum ValueType {
		Ml_Unknown,
		Ml_Natural,
		Ml_Integer,
		Ml_Real,
		Ml_String,
		Ml_TimeMmSsCc,
		Ml_TimeHhMmSs,
		Ml_RealFormated,
		Ml_TimeMmSs,
		Ml_Ascii7bit,
		Ml_Real3Decimals,
		Ml_TimeHhMmSs_24,
		Ml_TimeHhMm,
		Ml_Percent,
		Ml_Hexa,
		Ml_TimeHhMmSsOrMmSs,
		Ml_TimeHhMmFromSeconds,
	};
/*!

*/
			Text Value;
/*!

*/
			Void StartEdition();
/*!

*/
			Void SetText(Text NewText,Boolean SendSubmitEvent);
/*!

*/
			CMlEntry::ETextFormat TextFormat;
/*!

*/
			Real Opacity;
/*!

*/
			Vec3 TextColor;
/*!

*/
			Real TextSizeReal;
/*!

*/
			Integer MaxLine;
/*!

*/
			Boolean AutoNewLine;
/*!

*/
			CMlEntry::ValueType GetValueType();
/*!

*/
			Void SetValueType(CMlEntry::ValueType ValueType);
};

/*!
* \brief Manialink control.
*
* Supported declare modes :
* - Local
*/
class CMlMinimap : public CMlControl {
public :
/*!

*/
			Vec3 WorldPosition;
/*!

*/
			Vec2 MapPosition;
/*!

*/
			Real MapYaw;
/*!
Values in range (0.500000-10.000000)
*/
			Real ZoomFactor;
/*!

*/
			Boolean Underground;
/*!

*/
			Boolean DisableAutoUnderground;
/*!

*/
			Void Fog_SetAll(Real Value);
/*!

*/
			Void Fog_ClearDisk(Vec3 WorldCenter,Real Radius,Real FadeSize);
};

/*!
* \brief Documentation for class CMlQuad
*
* Supported declare modes :
* - Local
*/
class CMlQuad : public CMlControl {
public :
	/*!
	
	*/
	enum EKeepRatioMode {
		Inactive,
		Clip,
		Fit,
	};
	/*!
	
	*/
	enum EBlendMode {
		Default,
		Add,
	};
/*!

*/
			Void ChangeImageUrl(Text fieldName);
/*!

*/
			CImage Image;
/*!

*/
			Text ImageUrl;
/*!

*/
			Text ImageUrlFocus;
/*!

*/
			Text AlphaMaskUrl;
/*!

*/
			Text Style;
/*!

*/
			Text Substyle;
/*!

*/
			Boolean StyleSelected;
/*!

*/
	const	Boolean DownloadInProgress;
/*!

*/
			Vec3 Colorize;
/*!

*/
			Vec3 ModulateColor;
/*!

*/
			Vec3 BgColor;
/*!

*/
			Vec3 BgColorFocus;
/*!

*/
			Real Opacity;
/*!

*/
			CMlQuad::EKeepRatioMode KeepRatio;
/*!

*/
			CMlQuad::EBlendMode Blend;
/*!

*/
			Void RefreshImages();
};

/*!
* \brief Manialink entry.
*
* Supported declare modes :
* - Local
*/
class CMlLabel : public CMlControl {
public :
	/*!
	
	*/
	enum EBlendMode {
		Default,
		Add,
	};
/*!

*/
			Text Style;
/*!

*/
			Text Substyle;
/*!

*/
			Text TextFont;
/*!

*/
			Void SetText(Text NewText);
/*!

*/
			Text Value;
/*!

*/
	const	Integer ValueLineCount;
/*!

*/
			Integer MaxLine;
/*!

*/
			Real LineSpacing;
/*!

*/
			Real ItalicSlope;
/*!

*/
			Boolean AppendEllipsis;
/*!

*/
			Boolean AutoNewLine;
/*!

*/
			Real Opacity;
/*!
Used to include styling attributes like $s,$o...
*/
			Text TextPrefix;
/*!

*/
			Vec3 TextColor;
/*!

*/
			Real TextSizeReal;
/*!

*/
			CMlLabel::EBlendMode Blend;
/*!

*/
			Real ComputeWidth(Text Text);
/*!

*/
			Real ComputeWidth(Text Text,Boolean Translated);
/*!

*/
			Real ComputeHeight(Text Text);
};

/*!
* \brief Documentation for class CParsingDocument
*/
class CParsingDocument : public CNod {
public :
/*!

*/
	const	Text TextContents;
/*!

*/
	const	CParsingNode Root;
/*!

*/
	const	Array<CParsingNode> Nodes;
/*!

*/
			CParsingNode GetFirstChild(Text Name);
};

/*!
* \brief An HTTP request.
*
* Supported declare modes :
* - Local
*/
class CHttpRequest : public CNod {
public :
/*!
Url of the request
*/
	const	Text Url;
/*!
Result available once IsCompleted and StatusCode = 200
*/
	const	Text Result;
/*!
HTTP status code
*/
	const	Integer StatusCode;
/*!

*/
	const	Boolean IsCompleted;
};

/*!
* \brief An HTTP event.
*/
class CHttpEvent : public CNod {
public :
	/*!
	
	*/
	enum EType {
		RequestComplete,
	};
/*!

*/
	const	CHttpEvent::EType Type;
/*!
Request triggering the event
*/
	const	CHttpRequest Request;
};

/*!
* \brief This is a video playback handle.
*/
class CVideo : public CNod {
public :
	/*!
	
	*/
	enum ETextureFilter {
		Default,
		Point,
	};
/*!

*/
	const	CImage Image;
/*!

*/
			Boolean IsLooping;
/*!

*/
	const	Boolean DownloadInProgress;
/*!

*/
	const	Real PlayLength;
/*!

*/
			Void BeginProcessing();
/*!

*/
			Void EndProcessing();
/*!

*/
	const	Boolean IsProcessing;
/*!
Automatically begin processing when the layer becomes visible and end when hidden.
*/
			Boolean AutoProcessing;
/*!

*/
			Void Play();
/*!

*/
			Void Pause();
/*!

*/
			Void Stop();
/*!

*/
	const	Boolean IsPlaying;
/*!

*/
			Real PlayCursor;
/*!

*/
			CVideo::ETextureFilter TextureFilter;
};

/*!
* \brief Documentation for class CAudioSource
*/
class CAudioSource : public CNod {
public :
/*!

*/
			Void Play();
/*!

*/
			Void Stop();
/*!

*/
	const	Boolean IsPlaying;
/*!

*/
	const	Boolean DownloadInProgress;
/*!

*/
			Real Volume;
/*!

*/
			Real FadeDuration;
/*!

*/
			Real VolumedB;
/*!

*/
			Real Pitch;
/*!

*/
			Vec3 RelativePosition;
/*!

*/
			Vec3 PanRadiusLfe;
/*!

*/
			Real PlayCursor;
/*!

*/
	const	Real PlayLength;
};

/*!
* \brief Documentation for class CAudioSourceMusic
*/
class CAudioSourceMusic : public CAudioSource {
public :
	/*!
	
	*/
	enum EUpdateMode {
		Cut,
		OnNextBar,
		OnNextHalfBar,
		OnNextBeat,
	};
/*!

*/
			Array<Real> Tracks_Volume;
/*!

*/
			Array<Real> Tracks_VolumedB;
/*!

*/
	const	Array<Text> Tracks_Name;
/*!

*/
	const	Array<Real> Tracks_Length;
/*!

*/
	const	Integer Tracks_Count;
/*!

*/
	const	Real BeatsPerMinute;
/*!

*/
	const	Real BeatDuration;
/*!

*/
	const	Integer BeatsPerBar;
/*!

*/
			CAudioSourceMusic::EUpdateMode UpdateMode;
/*!

*/
			Boolean Dbg_ForceIntensity;
/*!

*/
			Boolean Dbg_ForceSequential;
/*!

*/
			Boolean Dbg_ForceRandom;
/*!
Values in range (0.000000-1.000000)
*/
			Real LPF_CutoffRatio;
/*!
Values in range (0.100000-20.000000)
*/
			Real LPF_Q;
/*!
Values in range (0.000000-1.000000)
*/
			Real HPF_CutoffRatio;
/*!
Values in range (0.100000-20.000000)
*/
			Real HPF_Q;
/*!

*/
			Real FadeTracksDuration;
/*!

*/
			Real FadeFiltersDuration;
/*!

*/
			Void MuteAllTracks();
/*!

*/
			Void UnmuteAllTracks();
/*!

*/
			Void NextVariant();
/*!

*/
			Void NextVariant(Boolean IsIntensityDecreasing);
/*!

*/
			Void EnableSegment(Text SegmentName);
/*!

*/
			Boolean UseNewImplem;
};

/*!
* \brief Documentation for class CInputEvent
*/
class CInputEvent : public CNod {
public :
	/*!
	
	*/
	enum EType {
		PadButtonPress,
	};
	/*!
	
	*/
	enum EButton {
		Left,
		Right,
		Up,
		Down,
		A,
		B,
		X,
		Y,
		L1,
		R1,
		LeftStick,
		RightStick,
		Menu,
		View,
		LeftStick_Left,
		LeftStick_Right,
		LeftStick_Up,
		LeftStick_Down,
		RightStick_Left,
		RightStick_Right,
		RightStick_Up,
		RightStick_Down,
		L2,
		R2,
		None,
	};
/*!

*/
	const	CInputEvent::EType Type;
/*!

*/
	const	CInputPad Pad;
/*!

*/
	const	CInputEvent::EButton Button;
/*!

*/
	const	Boolean IsAutoRepeat;
/*!

*/
	const	Integer KeyCode;
/*!

*/
	const	Text KeyName;
};

/*!
* \brief game controller.
*/
class CInputPad : public CNod {
public :
	/*!
	
	*/
	enum EButton {
		Left,
		Right,
		Up,
		Down,
		A,
		B,
		X,
		Y,
		L1,
		R1,
		LeftStick,
		RightStick,
		Menu,
		View,
		LeftStick_Left,
		LeftStick_Right,
		LeftStick_Up,
		LeftStick_Down,
		RightStick_Left,
		RightStick_Right,
		RightStick_Up,
		RightStick_Down,
		L2,
		R2,
		None,
	};
	/*!
	
	*/
	enum EPadType {
		Keyboard,
		Mouse,
		Generic,
		XBox,
		PlayStation,
		Vive,
	};
/*!

*/
	const	Integer ControllerId;
/*!

*/
	const	Ident UserId;
/*!

*/
	const	CInputPad::EPadType Type;
/*!

*/
	const	Text ModelName;
/*!

*/
	const	Integer IdleDuration;
/*!

*/
	const	Integer Left;
/*!

*/
	const	Integer Right;
/*!

*/
	const	Integer Up;
/*!

*/
	const	Integer Down;
/*!

*/
	const	Integer A;
/*!

*/
	const	Integer B;
/*!

*/
	const	Integer X;
/*!

*/
	const	Integer Y;
/*!

*/
	const	Integer L1;
/*!

*/
	const	Integer R1;
/*!

*/
	const	Integer LeftStickBut;
/*!

*/
	const	Integer RightStickBut;
/*!

*/
	const	Integer Menu;
/*!

*/
	const	Integer View;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real LeftStickX;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real LeftStickY;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real RightStickX;
/*!
Values in range (-1.000000-1.000000)
*/
	const	Real RightStickY;
/*!
Values in range (0.000000-1.000000)
*/
	const	Real L2;
/*!
Values in range (0.000000-1.000000)
*/
	const	Real R2;
/*!

*/
	const	Array<CInputPad::EButton> ButtonEvents;
/*!

*/
			Void ClearRumble();
/*!
Duration = 0 --> forever.
*/
			Void AddRumble(Integer Duration,Real LargeMotor,Real SmallMotor);
/*!
(only works on PS4.)  set to (0,0,0) to reset back to default color.
*/
			Void SetColor(Vec3 Color);
};

/*!
* \brief Asynchronous task result.
*/
class CTaskResult : public CNod {
public :
/*!
Returns a boolean indicating if the task is still processing.
*/
	const	Boolean IsProcessing;
/*!
Returns a boolean indicating if the task has succeeded.
*/
	const	Boolean HasSucceeded;
/*!
Returns a boolean indicating if the task has failed or has been canceled.
*/
	const	Boolean HasFailed;
/*!
Returns a boolean indicating if the task has been canceled.
*/
	const	Boolean IsCanceled;
/*!
Returns the type of the error if the task has failed.
*/
	const	Text ErrorType;
/*!
Returns the code of the error if the task has failed.
*/
	const	Text ErrorCode;
/*!
Returns the description of the error if the task has failed.
*/
	const	Text ErrorDescription;
/*!

*/
			Void Cancel();
};

/*!
* \brief Documentation for class CCampaign
*/
class CCampaign : public CNod {
public :
/*!

*/
	const	Text CampaignId;
/*!

*/
			Array<CMapGroup> MapGroups;
/*!

*/
			Integer GetMapGroupCount();
/*!

*/
			CMapGroup GetMapGroup(Integer Index);
/*!

*/
			CMapInfo GetNextMap(CMapInfo CurrentMapInfo);
/*!

*/
			Text ScoreContext;
/*!

*/
			Boolean OfficialRecordEnabled;
};

/*!
* \brief Results containing a list of map info.
*/
class CTaskResult_MapList : public CTaskResult {
public :
/*!
Path of the parent zone.
*/
	const	Text ParentPath;
/*!
Path of the current zone.
*/
	const	Text Path;
/*!
List of the map info. Array of CMapInfo objects.
*/
	const	Array<CMapInfo> MapInfos;
/*!
List of the sub folders. Array of string.
*/
	const	Array<Text> SubFolders;
};

/*!
* \brief Task result containing a map info from NadeoServices.
*/
class CTaskResult_NSMap : public CWebServicesTaskResult_NadeoServicesMap {
public :
/*!
Map info retrieve from NadeoServices contained by this result.
*/
	const	CNadeoServicesMap Map;
};

/*!
* \brief Task result containing a list of map info from NadeoServices.
*/
class CTaskResult_NSMapList : public CWebServicesTaskResult_NadeoServicesMapList {
public :
/*!
List of map info retrieve from NadeoServices contained by this result.
*/
	const	Array<CNadeoServicesMap> MapList;
};

/*!
* \brief Task result containing a Skin info from NadeoServices.
*/
class CTaskResult_NSSkin : public CWebServicesTaskResult_NadeoServicesSkin {
public :
/*!
Skin info retrieve from NadeoServices contained by this result.
*/
	const	CNadeoServicesSkin Skin;
};

/*!
* \brief Task result containing a list of Skin info from NadeoServices.
*/
class CTaskResult_NSSkinList : public CWebServicesTaskResult_NadeoServicesSkinList {
public :
/*!
List of Skin info retrieve from NadeoServices contained by this result.
*/
	const	Array<CNadeoServicesSkin> SkinList;
};

/*!
* \brief Task result containing a ghost.
*/
class CTaskResult_Ghost : public CTaskResult {
public :
/*!
Ghost contained by this result.
*/
	const	CGhost Ghost;
};

/*!
* \brief Results containing a list of replay info.
*/
class CTaskResult_ReplayList : public CTaskResult {
public :
/*!
Path of the parent zone.
*/
	const	Text ParentPath;
/*!
Path of the current zone.
*/
	const	Text Path;
/*!
List of the replay info. Array of CReplayInfo objects.
*/
	const	Array<CReplayInfo> ReplayInfos;
/*!
List of the sub folders. Array of string.
*/
	const	Array<Text> SubFolders;
};

/*!
* \brief Results containing a list of ghost.
*/
class CTaskResult_GhostList : public CTaskResult {
public :
/*!
List of ghost. Array of CGhost.
*/
	const	Array<CGhost> Ghosts;
};

/*!
* \brief Results containing a list of media info.
*/
class CTaskResult_FileList : public CTaskResult {
public :
/*!
Path of the parent zone.
*/
	const	Text ParentPath;
/*!
Path of the current zone.
*/
	const	Text Path;
/*!
List of files. Array of string.
*/
	const	Array<Text> Files;
/*!
List of the sub folders. Array of string.
*/
	const	Array<Text> SubFolders;
};

/*!
* \brief Results containing a list of GameMode info.
*/
class CTaskResult_GameModeList : public CTaskResult {
public :
/*!
Description of the GameMode
*/
	const	Array<CTaskResult_ModeInfo> GameModes;
};

/*!
* \brief A player is the incarnation of the user in the playground.
*
* Supported declare modes :
* - Local
* - NetworkRead
* - NetworkWrite
*/
class CPlayer : public CEntity {
public :
/*!

*/
	const	CUser User;
/*!

*/
	const	Integer RequestedClan;
/*!

*/
	const	Boolean RequestsSpectate;
};

/*!
* \brief Task result containing a list of map record info from NadeoServices.
*/
class CTaskResult_MapRecordList : public CWebServicesTaskResult_MapRecordList {
public :
/*!
List of map record info retrieve from NadeoServices contained by this result.
*/
	const	Array<CMapRecord> MapRecordList;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_Natural : public CTaskResult {
public :
/*!

*/
	const	Integer Value;
};

/*!
* \brief List of all buddies record for a map.
*/
class CTaskResult_BuddiesChallengeRecord : public CTaskResult {
public :
/*!
Login of the user who has launched the task.
*/
	const	Text Login;
/*!

*/
	const	Array<CHighScoreComparison> BuddiesChallengeRecord;
/*!
Sort the results by opponent record count.
*/
			Void SortByOpponentCount();
/*!
Sort the results by opponent display name.
*/
			Void SortByOpponentDisplayName();
/*!
Sort the results by opponent login.
*/
			Void SortByOpponentLogin();
/*!
Sort the results by opponent record date.
*/
			Void SortByOpponentRecordDate();
/*!
Sort the results by opponent record time.
*/
			Void SortByOpponentRecordTime();
};

/*!
* \brief Results for comparison of challenge records with all the buddies.
*/
class CTaskResult_BuddiesChallengeRecordsComparison : public CTaskResult {
public :
/*!
Login of the user who has launched the task.
*/
	const	Text Login;
/*!
List of comparison summary between user records and buddy records. Array of CHighScoreComparisonSummary objects.
*/
	const	Array<CHighScoreComparisonSummary> BuddiesComparison;
/*!
Sort the results by user best record count.
*/
			Void SortByPlayerCount();
/*!
Sort the results by opponent login.
*/
			Void SortByOpponentLogin();
/*!
Sort the results by opponent best record count.
*/
			Void SortByOpponentCount();
/*!
Sort the results by opponent last record date.
*/
			Void SortByOpponentDate();
/*!
Sort the results by opponent display name.
*/
			Void SortByOpponentDisplayName();
};

/*!
* \brief Results for comparison of challenge records between a user and one of its buddy.
*/
class CTaskResult_BuddyChallengeRecordsComparison : public CTaskResult {
public :
/*!
Login of the user who has launched the task.
*/
	const	Text Login;
/*!
Buddy login.
*/
	const	Text BuddyLogin;
/*!
List of best challenge records for user. Array of CHighScoreComparison objects.
*/
	const	Array<CHighScoreComparison> PlayerBestRecordsComparison;
/*!
List of best challenge records for buddy. Array of CHighScoreComparison objects.
*/
	const	Array<CHighScoreComparison> BuddyBestRecordsComparison;
/*!
Sort the results by map name.
*/
			Void SortByMapName();
/*!
Sort the results by record time.
*/
			Void SortByRecordTime();
/*!
Sort the results by record time diff.
*/
			Void SortByRecordTimeDiff();
/*!
Sort the results by record date.
*/
			Void SortByRecordDate();
};

/*!
* \brief Results containing a part of the leaderboard.
*/
class CTaskResult_NaturalLeaderBoardInfoList : public CTaskResult {
public :
/*!
Starting index.
*/
	const	Integer FromIndex;
/*!
Number of item contained.
*/
	const	Integer Count;
/*!
List of the ranking info. Array of CNaturalLeaderBoardInfo objects.
*/
	const	Array<CNaturalLeaderBoardInfo> LeaderBoardInfo;
};

/*!
* \brief Task result containing a season.
*/
class CTaskResult_Season : public CWebServicesTaskResult_Season {
public :
/*!
Season info contained by this result.
*/
	const	CSeason Season;
};

/*!
* \brief Task result containing a list of season.
*/
class CTaskResult_SeasonList : public CWebServicesTaskResult_SeasonList {
public :
/*!
List of season contained by this result.
*/
	const	Array<CSeason> SeasonList;
};

/*!
* \brief Results containing a part of the leaderboard.
*/
class CTaskResult_RealLeaderBoardInfoList : public CTaskResult {
public :
/*!
Starting index.
*/
	const	Integer FromIndex;
/*!
Number of item contained.
*/
	const	Integer Count;
/*!
List of the ranking info. Array of CRealLeaderBoardInfo objects.
*/
	const	Array<CRealLeaderBoardInfo> LeaderBoardInfo;
};

/*!
* \brief Task result containing a last year summary of account trophy.
*/
class CTaskResult_AccountTrophyLastYearSummary : public CWebServicesTaskResult_AccountTrophyLastYearSummary {
public :
/*!
Last year summary of account trophy contained by this result.
*/
	const	CAccountTrophyLastYearSummary Summary;
};

/*!
* \brief Task result containing the settings of a solo medal trophy achievement.
*/
class CTaskResult_TrophySoloMedalAchievementSettings : public CWebServicesTaskResult_TrophySoloMedalAchievementSettings {
public :
/*!
Settings of a solo medal trophy achievement contained by this result.
*/
	const	CTrophySoloMedalAchievementSettings Settings;
};

/*!
* \brief Results containing a list of zones.
*/
class CTaskResult_ZoneList : public CTaskResult {
public :
/*!
Number of zones.
*/
	const	Integer ZoneCount;
/*!
List of zones. Array of CRankingsZone objects.
*/
	const	Array<CRankingsZone> Zones;
/*!

*/
			CRankingsZone GetZone(Text ZoneId);
};

/*!
* \brief Local profile settings.
*/
class CUserV2Profile : public CNod {
public :
	/*!
	
	*/
	enum EMapEditorMode {
		Ask,
		Advanced,
	};
	/*!
	
	*/
	enum ECustomPlayerModels {
		All,
		OnlyTextures,
		None,
	};
	/*!
	
	*/
	enum EInputMouseReleaseKey {
		LeftAlt,
		RightAlt,
		LeftCtrl,
		RightCtrl,
	};
	/*!
	
	*/
	enum EPlayerVisibility {
		Hidden,
		Ghost,
		Opaque,
	};
/*!

*/
	const	Boolean CanChangePassword;
/*!

*/
	const	Boolean CanChangeNickName;
/*!
avatar, horn and podium pose
*/
	const	Boolean CanChangeAvatar;
/*!

*/
	const	Boolean CanChangeSkin;
/*!

*/
	const	Boolean CanChangeZone;
/*!

*/
	const	Boolean CanChangeGroups;
/*!

*/
			Void Account_ResetChanges();
/*!

*/
			Text Account_Name;
/*!

*/
			Text Account_EMail;
/*!

*/
			Boolean Account_AcceptNews;
/*!

*/
			Boolean Account_EnableAutoConnect;
/*!
Values in range (0.000000-1.000000)
*/
			Real User_LightTrailHue;
/*!
Values in range (0.500000-2.000000)
*/
			Real User_HornPitch;
/*!

*/
			Text User_Description;
/*!

*/
			Text User_ClubLinkUrl;
/*!

*/
			Text User_Trigram;
/*!

*/
			Boolean Custom_EnableAvatars;
/*!

*/
			Boolean Custom_EnableChat;
/*!

*/
			CUserV2Profile::ECustomPlayerModels Custom_PlayerModels;
/*!

*/
			Boolean Custom_EnableUnlimitedHorns;
/*!
Favoured way to open the Map Editor
*/
			CUserV2Profile::EMapEditorMode Editors_MapEditorMode;
/*!

*/
			Boolean Online_AutoSaveReplay;
/*!

*/
			Boolean Online_SaveRoundReplaysSeparately;
/*!

*/
			CUserV2Profile::EPlayerVisibility Online_OpponentVisibility;
/*!

*/
			Boolean Title_IsForbiddenWithParentalLock;
/*!

*/
			Integer AddictionLimiter_DailyQuotaMinutes;
/*!

*/
			Boolean Steam_OpenLinksInSteam;
/*!

*/
			Boolean Steam_SynchonizeWorkshopFiles;
/*!

*/
			Boolean Interface_CrosshairEnableCustomColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_CrosshairSaturation;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_CrosshairLinearHue;
/*!
Values in range (0.100000-2.000000)
*/
			Real Interface_CrosshairSize;
/*!
Values in range (0.100000-1.000000)
*/
			Real Interface_CrosshairOpacity;
/*!

*/
			Text Interface_CrosshairName;
/*!
Values in range (0.100000-2.000000)
*/
			Real Interface_PlayerShieldScale;
/*!

*/
			Boolean Interface_AllyEnableCustomColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_AllyLinearHue;
/*!

*/
			Boolean Interface_OppoEnableCustomColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_OppoLinearHue;
/*!

*/
			Boolean Interface_BeaconUseProfileColor;
/*!
Values in range (0.000000-1.000000)
*/
			Real Interface_BeaconOpacity;
/*!
Values in range (0.100000-5.000000)
*/
			Real Interface_BeaconSize;
/*!
Values in range (0.500000-15.000000)
*/
			Real Interface_BeaconDuration;
/*!

*/
			CUserV2Profile::EPlayerVisibility Interface_InternalCamLocalPlayerVisibility;
/*!

*/
			Boolean Interface_UseOldInternalCam;
/*!

*/
			Boolean Interface_ShowSpecialsFeedback;
/*!

*/
			Boolean Inputs_MouseLookInvertY;
/*!

*/
			CUserV2Profile::EInputMouseReleaseKey Inputs_MouseReleaseKey;
/*!
Values in range (0.100000-3.000000)
*/
			Real Inputs_MouseScaleY;
/*!
Values in range (0.100000-3.000000)
*/
			Real Inputs_MouseScaleFreeLook;
/*!
Values in range (0.000000-3.000000)
*/
			Real Inputs_MouseAccel;
/*!
Values in range (-1.000000-1.000000)
*/
			Real Inputs_MouseSensitivityDefault;
/*!
Values in range (-1.000000-1.000000)
*/
			Real Inputs_MouseSensitivityLaser;
/*!

*/
			Real Inputs_MouseSensitivityDefault_Raw;
/*!

*/
			Real Inputs_MouseSensitivityLaser_Raw;
/*!

*/
			Array<CVehicleSettings> Inputs_Vehicles;
/*!

*/
			Boolean Adverts_Enabled;
/*!

*/
			Boolean Adverts_UsePersonnalData;
};

/*!
* \brief Asynchronous task result.
*/
class CTaskResult_StringIntList : public CTaskResult {
public :
/*!

*/
	const	Array<Text> Values;
};

/*!
* \brief Masterserver user info.
*/
class CMasterServerUser : public CNod {
public :
/*!

*/
	const	Boolean NeedToChangeZone;
/*!
Number of level in the full path of the user zone.
*/
	const	Integer ZoneLevelCount;
/*!
Returns the zone path of the indicated level.
*/
			Text GetZone(Integer ZoneLevel);
/*!

*/
	const	Integer MultiInternetPlayTimeLeft;
	/*!
	
	*/
	enum EMasterServerConnectionStatus {
		NotConnected,
		Connecting,
		Connected,
		Disconnecting,
	};
/*!
Login.
*/
	const	Text Login;
/*!
Display name.
*/
	const	Text DisplayName;
/*!
Connection status: NotConnected, Connecting, Connected or Disconnecting.
*/
	const	CMasterServerUser::EMasterServerConnectionStatus ConnectionStatus;
/*!

*/
	const	Text LastConnectionErrorType;
/*!

*/
	const	Text LastConnectionErrorCode;
/*!

*/
	const	Text LastConnectionErrorDescription;
/*!
Return if the user has a Uplay profile.
*/
	const	Boolean HasUplayProfile;
/*!
Return if the user has a accepted DNA.
*/
	const	Boolean HasAcceptedNDA;
/*!

*/
	const	Array<CNetUbiServicesNews> UbiServicesSpaceNews;
/*!

*/
	const	Array<CNetUbiServicesNews> UbiServicesProfileNews;
};

/*!
* \brief Asynchronous task result.
*/
class CTaskResult_Session_Get : public CTaskResult {
public :
/*!

*/
	const	Text SessionId;
/*!

*/
	const	Text ServerLogin;
/*!

*/
	const	Text ServerPassword;
};

/*!
* \brief Documentation for class CModuleMenu
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CModuleMenu : public CManiaAppTitle {
public :
/*!

*/
			Void Menu_Goto(Text PageId);
/*!

*/
			Void Menu_Back();
/*!

*/
			Void Menu_Previous();
/*!

*/
			Void Menu_Quit();
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CManiaAppEvent : public CBaseConstEvent {
public :
	/*!
	
	*/
	enum EType {
		LayerCustomEvent,
		KeyPress,
		ExternalCustomEvent,
		MenuNavigation,
	};
	/*!
	
	*/
	enum EMenuNavAction {
		Up,
		Right,
		Left,
		Down,
		Select,
		Cancel,
		PageUp,
		PageDown,
		AppMenu,
		Action1,
		Action2,
		ScrollUp,
		ScrollDown,
	};
/*!

*/
	const	CManiaAppEvent::EType Type;
/*!

*/
	const	CUILayer CustomEventLayer;
/*!

*/
	const	Text CustomEventType;
/*!

*/
	const	Array<Text> CustomEventData;
/*!

*/
	const	Text ExternalEventType;
/*!

*/
	const	Array<Text> ExternalEventData;
/*!

*/
	const	CManiaAppEvent::EMenuNavAction MenuNavAction;
/*!

*/
	const	Boolean IsActionAutoRepeat;
/*!

*/
	const	Integer KeyCode;
/*!

*/
	const	Text KeyName;
};

/*!
* \brief API for titles in edition mode.
*/
class CTitleEdition : public CNod {
public :
	/*!
	
	*/
	enum EDrive {
		TitleReadable,
		Title,
		User,
	};
/*!

*/
	const	CTitle TitleMaker;
/*!
PackCreator - only available when the title author is the current logged user.
*/
	const	CPackCreator PackCreator;
/*!

*/
	const	Text EditedTitleId;
/*!

*/
	const	CPackCreatorTitleInfo EditedTitleInfo;
/*!
Will copy file 'FileName' from the UserDir to the TitleDir, including its dependencies.
*/
			Void File_ImportFromUser(Text FileName);
/*!
Will move or copy file 'OrigName' to 'DestName'. If DestName is a '\' terminated folder path, keeps the orginial short name.
*/
			Void File_Move(Text OrigName,Text DestNameOrFolder,Boolean KeepOriginalCopy);
/*!

*/
			Boolean File_Exists(Text FileName,CTitleEdition::EDrive InDrive);
/*!

*/
			Void File_Delete(Text Name);
/*!

*/
			Void File_WriteText(Text FileName,Text Text);
/*!

*/
			Text File_ReadText(Text FileName);
/*!

*/
			Void Dialog_ImportFiles();
/*!

*/
	const	Boolean Dialog_IsFinished;
/*!

*/
	const	Boolean Dialog_Success;
/*!

*/
	const	Boolean Dialog_Aborted;
/*!

*/
			Void OpenTitleFolderInExplorer();
/*!

*/
			Void ReloadTitleDesc();
/*!

*/
			Void SaveTitleDesc();
/*!
nb: The maps from the campaign are automatically added to the pack, no need to Build_AddFile().
*/
			Void SetTitleCampaign(Integer CampaignNum,Text ScoreContext,Text MapsFolderNameOrPlayListName,Boolean OfficialRecordEnabled);
/*!

*/
			Void SetTitleCampaign(Integer CampaignNum,Text ScoreContext,Text MapsFolderNameOrPlayListName,Boolean OfficialRecordEnabled,Boolean DisableUnlockSystem);
};

/*!
* \brief Manager of buddies instant messaging.
*/
class CNotificationsConsumer : public CNod {
public :
	/*!
	
	*/
	enum EFilterPriority {
		All,
		MoreThanMemo,
		MoreThanNotice,
	};
/*!
Events
*/
	const	Array<CNotificationsConsumerEvent> Events;
/*!
List of the Notifications.
*/
	const	Array<CNotificationsConsumerNotification> Notifications;
/*!

*/
	const	Array<CNotificationsConsumerNotification> FilteredNotifications;
/*!

*/
			CNotificationsConsumer::EFilterPriority Filter_Priority;
};

/*!
* \brief Documentation for class CBadgeManager
*/
class CBadgeManager : public CNod {
public :
/*!

*/
	const	Array<CBadge> Badges;
/*!

*/
			CBadge BadgeCreate();
/*!

*/
			Void BadgeDestroy(CBadge Badge);
/*!

*/
			Void BadgeCopy(CBadge Source,CBadge Destination);
/*!

*/
			Void BadgeReadFromProfile(CBadge Badge,Ident UserId);
/*!

*/
			Void BadgeWriteToProfile(CBadge Badge,Ident UserId);
/*!

*/
			Boolean ProfileIsReady(Ident UserId);
};

/*!
* \brief Allows handling of match-settings files
*/
class CMatchSettingsManager : public CNod {
public :
/*!
Clear all matchsettings and reload them from disk. Be aware that any non-saved changes will be lost.
*/
			Void MatchSettings_Refresh();
/*!
Create a new matchsettings file.
*/
			CMatchSettings MatchSettings_Create(Text FilePath);
/*!
Save a matchsettings file.
*/
			Void MatchSettings_Save(CMatchSettings MatchSettings);
/*!

*/
			CMatchSettings MatchSettings_SaveAs(Text FilePath,CMatchSettings MatchSettings);
/*!

*/
			Void MatchSettings_EditScriptSettings(CMatchSettings MatchSettings);
/*!

*/
	const	Boolean MatchSettings_EditScriptSettings_Ongoing;
/*!
Array of the matchsettings
*/
	const	Array<CMatchSettings> MatchSettings;
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CMapEditorPluginEvent : public CManiaAppEvent {
public :
	/*!
	
	*/
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		CursorSelectionBegin,
		CursorSelectionEnd,
		CursorChange,
		MapModified,
		EditorInput,
		MapSavedOrSaveCancelled,
		EditAnchor,
		EditObjectives,
		StartValidation,
		StartTest,
	};
	/*!
	
	*/
	enum EInput {
		Unknown,
		Menu,
		SwitchToRace,
		Undo,
		Redo,
		CursorUp,
		CursorRight,
		CursorDown,
		CursorLeft,
		CursorRaise,
		CursorLower,
		CursorTurn,
		CursorPick,
		CursorPlace,
		CursorDelete,
		CameraUp,
		CameraRight,
		CameraDown,
		CameraLeft,
		CameraZoomNext,
		Camera0,
		Camera1,
		Camera3,
		Camera7,
		Camera9,
		PivotChange,
		CursorTurnSlightly,
		CursorTurnSlightlyAntiClockwise,
		IconUp,
		IconRight,
		IconDown,
		IconLeft,
		RemoveAll,
		Save,
		SaveAs,
		MapStyle,
		ClassicMapEditor,
		SelectAll,
		Copy,
		Cut,
		Paste,
	};
/*!

*/
	const	CMapEditorPluginEvent::Type Type;
/*!

*/
	const	CMapEditorPluginEvent::EInput Input;
/*!

*/
	const	Ident EditedAnchorDataId;
/*!

*/
	const	Boolean IsFromPad;
/*!

*/
	const	Boolean IsFromMouse;
/*!

*/
	const	Boolean IsFromKeyboard;
/*!

*/
	const	Boolean OnlyScriptMetadataModified;
/*!

*/
	const	Boolean MapSavedOrSaveCancelled;
};

/*!
* \brief Documentation for class CMapEditorInventory
*/
class CMapEditorInventory : public CNod {
public :
/*!

*/
	const	CMapEditorInventoryDirectory CurrentRootNode;
/*!

*/
	const	CMapEditorInventoryDirectory CurrentDirectory;
/*!

*/
	const	CMapEditorInventoryNode CurrentSelectedNode;
/*!

*/
			Array<CMapEditorInventoryNode> RootNodes;
/*!

*/
			Void EnterDirectory();
/*!

*/
			Void LeaveDirectory();
/*!

*/
			Void SelectArticle(CMapEditorInventoryArticle NodeArticle);
/*!

*/
			Void OpenDirectory(CMapEditorInventoryDirectory NodeDirectory);
/*!

*/
			Void SelectNode(CMapEditorInventoryNode Node);
/*!

*/
			Void OpenBrotherDirectory(Boolean NextOrElsePrevious);
/*!

*/
			Void SelectBrotherArticle(Boolean NextOrElsePrevious);
/*!

*/
			Void SelectBrotherNode(Boolean NextOrElsePrevious);
/*!

*/
			CMapEditorInventoryDirectory GetDirectoryAfter(CMapEditorInventoryNode Node);
/*!

*/
			CMapEditorInventoryDirectory GetDirectoryBefore(CMapEditorInventoryNode Node);
/*!

*/
			CMapEditorInventoryArticle GetArticleAfter(CMapEditorInventoryNode Node);
/*!

*/
			CMapEditorInventoryArticle GetArticleBefore(CMapEditorInventoryNode Node);
};

/*!
* \brief The model of a map block
*/
class CBlockModel : public CCollector {
public :
	/*!
	
	*/
	enum EWayPointType {
		Start,
		Finish,
		Checkpoint,
		None,
		StartFinish,
		Dispenser,
	};
/*!

*/
	const	Text Name;
/*!

*/
	const	Boolean IsRoad;
/*!

*/
	const	Boolean IsTerrain;
/*!

*/
	const	Boolean IsPodium;
/*!

*/
	const	CBlockModel::EWayPointType WaypointType;
/*!

*/
	const	Boolean NoRespawn;
/*!

*/
	const	Boolean IsClip;
/*!

*/
	const	CBlockModelVariantGround VariantGround;
/*!

*/
	const	CBlockModelVariantAir VariantAir;
};

/*!
* \brief Documentation for class CMacroblockModel
*
* Supported declare modes :
* - Local
* - Metadata
*/
class CMacroblockModel : public CCollector {
public :
/*!

*/
	const	Boolean IsGround;
/*!

*/
	const	Boolean HasStart;
/*!

*/
	const	Boolean HasFinish;
/*!

*/
	const	Boolean HasCheckpoint;
/*!

*/
	const	Boolean HasMultilap;
/*!

*/
	const	CBlockModel GeneratedBlockModel;
/*!

*/
			Void ClearScriptMetadata();
/*!

*/
	const	Text Name;
};

/*!
* \brief Documentation for class CBlock
*/
class CBlock : public CNod {
public :
	/*!
	
	*/
	enum CardinalDirections {
		North,
		East,
		South,
		West,
	};
/*!

*/
	const	Boolean CanHaveAnchor;
/*!

*/
			Void UseDefaultAnchor();
/*!

*/
			Void UseCustomAnchor();
/*!

*/
	const	Int3 Coord;
/*!

*/
	const	CMapEditorPlugin::CardinalDirections Dir;
/*!

*/
	const	CBlock::CardinalDirections Direction;
/*!

*/
	const	Array<CBlockUnit> BlockUnits;
/*!

*/
	const	CBlockModel BlockModel;
/*!

*/
			Boolean IsGhostBlock();
};

/*!
* \brief Documentation for class CMacroblockInstance
*/
class CMacroblockInstance : public CNod {
public :
/*!

*/
	const	CMacroblockModel MacroblockModel;
/*!

*/
	const	CBlockClipList ClipList;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
/*!

*/
	const	Int3 Coord;
/*!

*/
			Integer Order;
/*!

*/
			Integer UserData;
/*!

*/
	const	Array<Int3> UnitCoords;
/*!

*/
			Int3 GetSize();
};

/*!
* \brief Landmark of a map.
*
* Supported declare modes :
* - Metadata
*/
class CAnchorData : public CNod {
public :
	/*!
	
	*/
	enum EWaypointType {
		Start,
		Finish,
		Checkpoint,
		None,
		StartFinish,
		Dispenser,
	};
/*!

*/
	const	Text DefaultTag;
/*!

*/
	const	Integer DefaultOrder;
/*!

*/
			Text Tag;
/*!

*/
			Integer Order;
/*!

*/
	const	CAnchorData::EWaypointType WaypointType;
/*!

*/
	const	Vec3 Position;
};

/*!
* \brief Documentation for class CBlockClipList
*/
class CBlockClipList : public CNod {
public :
/*!

*/
	const	Array<CBlockClip> Clips;
/*!

*/
	const	Int3 Size;
/*!

*/
			Boolean SetClipListFromMacroblock(CMacroblockModel MacroBlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean SetClipListFromMacroblock(CMacroblockModel MacroBlockModel);
/*!

*/
			Boolean SetClipListFromBlock(CBlockModel BlockModel,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Boolean SetClipListFromBlock(CBlockModel BlockModel);
/*!

*/
			Void CreateAndAddClip(Text Name,Int3 Coord,Int3 Offset,CMapEditorPlugin::CardinalDirections Dir,Integer ClipId);
/*!

*/
			Boolean SetFromClipList(CBlockClipList ClipList,Int3 Coord,CMapEditorPlugin::CardinalDirections Dir);
/*!

*/
			Void RemoveClip(CBlockClip Clip);
/*!

*/
			Void ClearClips();
/*!

*/
			Void Destroy();
};

/*!
* \brief Documentation for class CBlockClip
*/
class CBlockClip : public CNod {
public :
/*!

*/
	const	Text Name;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
/*!

*/
	const	Int3 Coord;
/*!

*/
	const	Int3 Offset;
/*!

*/
			Integer ClipId;
/*!

*/
			Int3 GetConnectableCoord();
};

/*!
* \brief Documentation for class CMapEditorCamera
*/
class CMapEditorCamera : public CNod {
public :
	/*!
	
	*/
	enum EZoomLevel {
		Close,
		Medium,
		Far,
	};
	/*!
	
	*/
	enum ECameraVStep {
		Low,
		MediumLow,
		Medium,
		MediumHigh,
		High,
	};
/*!

*/
			Void ReleaseLock();
/*!

*/
			Void CenterOnCursor();
/*!

*/
			Void WatchStart();
/*!

*/
			Void WatchClosestFinishLine();
/*!

*/
			Void WatchClosestCheckpoint();
/*!

*/
			Void WatchWholeMap();
/*!

*/
			Void WatchCustomSelection();
/*!

*/
			Void MoveToMapCenter();
/*!

*/
			Boolean GetLock();
/*!

*/
			Boolean CanUse();
/*!

*/
			Void TurnH(Boolean Clockwise);
/*!

*/
			Void TurnH(Boolean Clockwise,Boolean HalfSteps);
/*!

*/
			Void TurnH(Boolean Clockwise,Boolean HalfSteps,Boolean Smooth);
/*!

*/
			Void TurnV(Boolean UpOrElseDown);
/*!

*/
			Void TurnV(Boolean UpOrElseDown,Boolean Smooth);
/*!

*/
			Void Move(CMapEditorPlugin::RelativeDirections RelativeDir);
/*!

*/
			Void FollowCursor(Boolean Follow);
/*!

*/
			Void CenterOnCursor(Boolean Smooth);
/*!

*/
			Void MoveToMapCenter(Boolean Smooth);
/*!

*/
			Void Watch(CBlock Block);
/*!

*/
			Void Watch(CBlock Block,Boolean Smooth);
/*!

*/
			Void Watch(CMacroblockInstance Macroblock);
/*!

*/
			Void Watch(CMacroblockInstance Macroblock,Boolean Smooth);
/*!

*/
			Void Watch(CBlockClip Clip);
/*!

*/
			Void Watch(CBlockClip Clip,Boolean Smooth);
/*!

*/
			Void WatchStart(Boolean Smooth);
/*!

*/
			Void WatchClosestFinishLine(Boolean Smooth);
/*!

*/
			Void WatchClosestCheckpoint(Boolean Smooth);
/*!

*/
			Void WatchWholeMap(Boolean Smooth);
/*!

*/
			Void WatchMacroblocks(Integer UserData);
/*!

*/
			Void WatchMacroblocks(Integer UserData,Boolean Smooth);
/*!

*/
			Void ZoomIn(Boolean Loop);
/*!

*/
			Void ZoomIn(Boolean Loop,Boolean Smooth);
/*!

*/
			Void ZoomOut(Boolean Loop);
/*!

*/
			Void ZoomOut(Boolean Loop,Boolean Smooth);
/*!

*/
			Void Zoom(CMapEditorCamera::EZoomLevel Level);
/*!

*/
			Void Zoom(CMapEditorCamera::EZoomLevel Level,Boolean Smooth);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections8 Direction);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections8 Direction,Boolean Smooth);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections Direction);
/*!

*/
			Void Look(CMapEditorPlugin::CardinalDirections Direction,Boolean Smooth);
/*!

*/
			Void SetVStep(CMapEditorCamera::ECameraVStep Step);
/*!

*/
			Void WatchCustomSelection(Boolean WatchCustomSelection);
};

/*!
* \brief Documentation for class CMapEditorCursor
*/
class CMapEditorCursor : public CNod {
public :
/*!

*/
			Void ReleaseLock();
/*!

*/
			Int3 Coord;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
/*!

*/
			CBlockModel BlockModel;
/*!

*/
			CBlockModel TerrainBlockModel;
/*!

*/
			CMacroblockModel MacroblockModel;
/*!

*/
			Real Brightness;
/*!

*/
			Boolean HideDirectionalArrow;
/*!

*/
			Void MoveToCameraTarget();
/*!

*/
			Void ResetCustomRGB();
/*!

*/
			Boolean GetLock();
/*!

*/
			Boolean CanUse();
/*!

*/
			Boolean Raise();
/*!

*/
			Boolean Lower();
/*!

*/
			Void FollowCameraTarget(Boolean Follow);
/*!

*/
			Void Rotate(Boolean CWOrCCW);
/*!

*/
			Void Move(CMapEditorPlugin::CardinalDirections CardinalDir);
/*!

*/
			Void Move(CMapEditorPlugin::CardinalDirections8 CardinalDir8);
/*!

*/
			Void Move(CMapEditorPlugin::RelativeDirections RelativeDir);
/*!

*/
			Void DisableMouseDetection(Boolean Disable);
/*!

*/
			Boolean CanPlace();
/*!

*/
			Boolean IsCustomRGBActivated();
/*!

*/
			Void SetCustomRGB(Vec3 Color);
};

/*!
* \brief Documentation for class CItemAnchor
*/
class CItemAnchor : public CNod {
public :
/*!

*/
	const	Vec3 Position;
};

/*!
* \brief Documentation for class CMapEditorConnectResults
*/
class CMapEditorConnectResults : public CNod {
public :
/*!

*/
			Boolean CanPlace;
/*!

*/
			Int3 Coord;
/*!

*/
			CMapEditorPlugin::CardinalDirections Dir;
};

/*!
* \brief Documentation for class CEditorModule
*
* Supported declare modes :
* - Metadata
*/
class CEditorModule : public CEditorBase {
public :
	/*!
	
	*/
	enum EModuleType {
		Undefined,
		Hud,
		Inventory,
		Store,
		ScoresTable,
		Equipment,
		MenuBase,
		MenuPage,
		Chrono,
		SpeedMeter,
		PlayerState,
		TeamState,
	};
/*!

*/
			Void NewModule(CEditorModule::EModuleType ModuleType);
/*!

*/
			Void OpenModule(Text Path);
/*!

*/
			Void Save();
/*!

*/
			Void SaveAs(Text Path);
/*!

*/
			Void SaveCopyAs(Text Path);
/*!

*/
			Void ForceExit();
/*!

*/
			Void SetPreviewBackground(Text Url);
/*!

*/
			Void ReloadPreview();
/*!

*/
	const	CModuleMenuModel EditedMenu;
/*!

*/
	const	CModuleMenuPageModel EditedMenuPage;
/*!

*/
	const	CModulePlaygroundHudModel EditedPlaygroundHud;
/*!

*/
			Void EditedPlaygroundHud_SetPreviewContext(Ident ContextId);
/*!

*/
			Void FileBrowser_Open();
/*!

*/
			Void FileBrowser_Save();
/*!

*/
	const	Boolean FileBrowser_IsRunning;
/*!

*/
	const	Text FileBrowser_FilePath;
/*!

*/
	const	Array<CEditorPluginModuleEvent> PendingEvents;
/*!

*/
			Boolean IsPreviewMode;
};

/*!
* \brief API for the mesh modeler.
*
* Supported declare modes :
* - Metadata
*/
class CEditorMesh : public CEditorAsset {
public :
	/*!
	
	*/
	enum EEdgesDisplay {
		Any,
		Borders,
		None,
	};
	/*!
	
	*/
	enum EEdgesConstraint {
		Any,
		Adjacent,
		Closed,
	};
	/*!
	
	*/
	enum EElemType {
		Vertex,
		Edge,
		Face,
		EVoxel,
		Any,
	};
	/*!
	
	*/
	enum EInteraction {
		Creation,
		Pick,
		PickJoint,
		VoxelPickDrag_Base,
		VoxelPickDrag_Creation,
		VoxelPickDrag_Delete,
		VoxelPickDrag_Select,
		VoxelPickDrag_Pick,
		VoxelPickDrag_SelectTranslation,
		VoxelPickDrag_SelectRotation,
		VoxelPickDrag_Paste,
		Selection,
		Translation,
		PickTranslation,
		ExtrudeTranslation,
		Rotation,
		PickRotation,
		Scale,
		Curve2D,
		Merge,
		Split,
		Mirror,
		Paste,
		PasteMaterial,
		BlocTransformation,
		None,
	};
	/*!
	
	*/
	enum ETexCoordLayer {
		Lightmap,
	};
	/*!
	
	*/
	enum EMaterialFilterCriterion {
		IsAutomatic,
		IsBadForHorizontalFaces,
		IsBadForVerticalFaces,
	};
	/*!
	
	*/
	enum EFilterKind {
		NoFilter,
		PassIfMatches,
		CutIfMatches,
	};
	/*!
	
	*/
	enum EUVEditorMode {
		UV,
		Atlas_ApplyOnClic,
		Atlas_SelectOnClic,
	};
	/*!
	
	*/
	enum EUVEditorProjectionType {
		Planar,
		Curve2D,
		Cylindrical2D,
		Cubic,
		Polyedric,
		Cylindrical,
		ApplyOnlyMaterial,
	};
	/*!
	
	*/
	enum ELayerType {
		AddGeometry,
		SubdivideSmooth,
		Translation,
		Rotation,
		Scale,
		Mirror,
		MoveToGround,
		Extrude,
		Subdivide,
		Chaos,
		Smooth,
		BorderTransition,
		BlocTransfo,
		Voxels,
		TriggerShape,
		RespawnPos,
		Sector,
		LightBall,
		None,
	};
	/*!
	
	*/
	enum ETitleCoreType {
		TrackMania,
		ShootMania,
	};
/*!

*/
			Boolean GoToMaterialEditor;
/*!

*/
			Boolean IsCreateMaterial;
/*!

*/
			Integer Layers_GetCount();
/*!

*/
			Ident Layers_GetLayerIdFromIndex(Integer LayerIndex);
/*!

*/
			Text Layers_GetLayerNameFromIndex(Integer LayerIndex);
/*!

*/
			CEditorMesh::ELayerType Layers_GetLayerTypeFromIndex(Integer LayerIndex);
/*!

*/
			Boolean Layers_GetLayerGeneratableFromIndex(Integer LayerIndex);
/*!

*/
			Void Layers_SetLayerGeneratableFromIndex(Integer LayerIndex,Boolean LayerGeneratability);
/*!

*/
			Void Layers_AddLayer(CEditorMesh::ELayerType LayerType);
/*!

*/
			Ident Layers_GetLayerIdSelected();
/*!

*/
			Void Layers_SetLayerIdSelected(Ident LayerId);
/*!

*/
			CEditorMesh::ELayerType Layers_GetLayerSelectedType();
/*!

*/
			Integer Layers_GetLayerSelectedIndex();
/*!

*/
			CEditorMesh::ELayerType Layers_GetEditedLayerType();
/*!

*/
			Text Layers_GetLayerSelectedName();
/*!

*/
			Void Layers_EditMask(Integer LayerIndex);
/*!

*/
			Void Layers_EditMaskValidate(Integer LayerIndex);
/*!

*/
			Void Layers_MoveSelectedLayerUp();
/*!

*/
			Void Layers_MoveSelectedLayerDown();
/*!

*/
			Void Layers_EditSelectedLayer(Boolean RegenerateSolid);
/*!

*/
			Void Layers_CloseEditSelectedLayer();
/*!

*/
			Void Layers_DeleteSelectedLayer();
/*!

*/
			Integer Transitions_GetCount();
/*!

*/
			Void Transitions_AddTransition(Text TransitionName,Integer TransitionPosition,Real TransitionSize);
/*!

*/
			Void Transitions_DeleteCurrentTransition();
/*!

*/
			Integer Transitions_GetTransitionSelectedIndex();
/*!

*/
			Void Transitions_SetTransitionSelectedIndex(Integer TransitionIndex);
/*!

*/
			Integer Transitions_GetTransitionCurrentPage();
/*!

*/
			Void Transitions_SetTransitionCurrentPage(Integer TransitionCurrentPage);
/*!

*/
			Text Transitions_GetTransitionNameFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionNameFromIndex(Integer TransitionIndex,Real TransitionName);
/*!

*/
			Boolean Transitions_GetTransitionVisibilityFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionVisibilityFromIndex(Integer TransitionIndex,Boolean TransitionVisibility);
/*!

*/
			Real Transitions_GetTransitionSizeFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionSizeFromIndex(Integer TransitionIndex,Real TransitionSize);
/*!

*/
			Integer Transitions_GetTransitionPositionFromIndex(Integer TransitionIndex);
/*!

*/
			Void Transitions_SetTransitionPositionFromIndex(Integer TransitionIndex,Integer TransitionPosition);
/*!

*/
			Boolean IsEditingLayer;
/*!

*/
			Integer SubdivideSmooth_NbSteps;
/*!

*/
			Real LayerValueAxisX;
/*!

*/
			Real LayerValueAxisY;
/*!

*/
			Real LayerValueAxisZ;
/*!

*/
			Boolean LayerIndep;
/*!

*/
			Real LayerValueParam1;
/*!

*/
			Real LayerValueParam2;
/*!

*/
			Real LayerValueParam3;
/*!

*/
			Real LayerValueParam4;
/*!

*/
			Boolean LayerIndexAxisX;
/*!

*/
			Boolean LayerIndexAxisY;
/*!

*/
			Boolean LayerIndexAxisZ;
/*!

*/
			Boolean Layer_IsVisible;
/*!

*/
			Boolean Layer_IsCollidable;
/*!

*/
			Text LayerName;
/*!

*/
			Boolean LayerGeneratable;
/*!

*/
			Boolean AddTransitionInProgress;
/*!

*/
			Text NewTransitionName;
/*!

*/
			Integer NewTransitionPosition;
/*!

*/
			Real NewTransitionSize;
/*!

*/
			Integer RotateAxis;
/*!

*/
	const	Boolean Tmp_UseParts;
/*!

*/
	const	Boolean IsDebug;
/*!

*/
			Boolean CameraEatingInputsScript;
/*!

*/
	const	Integer VertexCount;
/*!

*/
	const	Integer EdgeCount;
/*!

*/
	const	Integer FaceCount;
/*!

*/
			Void EditionBox_SetStep(Real Step);
/*!

*/
	const	Boolean EditionBox_IsPlaneOriented;
/*!

*/
	const	Real Scale;
/*!

*/
	const	Real Step;
/*!

*/
	const	Real Size;
/*!

*/
	const	Integer RotationStep;
/*!

*/
	const	Real RotationValue;
/*!

*/
	const	Real ScalingStep;
/*!

*/
	const	Real ScalingRatio;
/*!

*/
			Boolean DisplayVertices;
/*!

*/
			Boolean DisplayFaces;
/*!

*/
			Boolean DisplayJoints;
/*!

*/
			CEditorMesh::EEdgesDisplay DisplayEdges;
/*!

*/
			Void EditedMesh_Clear();
/*!

*/
			Void EditedMesh_Simplify();
/*!

*/
			Void EditedMesh_SimplifySelection();
/*!

*/
			Void EditedMesh_Lod(Real FacesRatio);
/*!

*/
			Void UVUnwrap(Ident SetHandle,CEditorMesh::ETexCoordLayer ETexCoordLayer);
/*!

*/
			Void Undo();
/*!

*/
			Void Redo();
/*!

*/
			Void SwitchPlane();
/*!

*/
			Void GridSnap_SetActive(Boolean IsActive);
/*!

*/
	const	Boolean GridSnap_IsActive;
/*!

*/
			Vec3 PickInfo_GetNormal();
/*!

*/
			Vec3 PickInfo_GetPosition();
/*!

*/
			Ident PickInfo_GetAnchorId();
/*!

*/
			Real PickInfo_GetEdgeLength();
/*!

*/
			Vec3 PickInfo_GetNextVertexPosition();
/*!

*/
			Ident PickInfo_GetMaterial();
/*!

*/
			Text PickInfo_GetError();
/*!

*/
			Void Part_SetAnchorPos(Vec3 Position);
/*!

*/
			Void Part_SetIsJoint(Boolean IsJoint);
/*!

*/
			Void Part_ClearAnchor();
/*!

*/
			Void Joint_Add(Vec3 Position);
/*!

*/
			Void Joint_Link(Ident IdChild,Ident IdParent);
/*!

*/
			Void Anchor_Remove(Ident Id);
/*!

*/
			Boolean IsUsingPhysicMatLib;
/*!

*/
	const	Integer MaterialGameplayIdNumber;
/*!

*/
	const	Integer MaterialsUpdateId;
/*!

*/
	const	Array<Ident> MaterialIds;
/*!

*/
	const	Array<Ident> MaterialPhysicsIds;
/*!

*/
	const	Array<Ident> MaterialDynaIds;
/*!

*/
	const	Array<Text> MaterialNames;
/*!

*/
	const	Array<Text> MaterialPhysicsNames;
/*!

*/
	const	Array<Text> MaterialDynaNames;
/*!

*/
			Ident Material_GetMaterialIdSelected();
/*!

*/
			Void Material_SetMaterialIdSelected(Ident MaterialEditorId);
/*!

*/
			Ident MaterialDyna_GetMaterialIdSelected();
/*!

*/
			Void MaterialDyna_SetMaterialIdSelected(Ident DynaMaterialType);
/*!

*/
			Integer Material_GetSubTexIndexSelected();
/*!

*/
			Integer Material_MaterialLibGetCount();
/*!

*/
			Void Material_SetDefault(Ident MaterialId);
/*!

*/
			Ident Material_GetDefault();
/*!

*/
			Ident MaterialPhysic_GetDefault();
/*!

*/
			Integer MaterialPhysic_GetIndex();
/*!

*/
			Integer MaterialPhysic_GetGameplayId(Ident MaterialId);
/*!

*/
			CImage MaterialPhysic_GetNextBitmap();
/*!

*/
			Ident MaterialDyna_GetDefault();
/*!

*/
			Void MaterialDyna_SetDefault(Ident MaterialId);
/*!

*/
			CImage Material_GetBitmapBase(Ident MaterialId);
/*!

*/
			CImage Material_GetBitmap(Ident MaterialId);
/*!

*/
			CImage MaterialDyna_GetBitmap(Ident MaterialId);
/*!

*/
			Boolean Material_MatchesCriterion(Ident MaterialId,CEditorMesh::EMaterialFilterCriterion ResultSetHandle);
/*!

*/
			Void Material_SetFilter(CEditorMesh::EMaterialFilterCriterion Criterion,CEditorMesh::EFilterKind FilterKind);
/*!

*/
			CEditorMesh::EFilterKind Material_GetFilter(CEditorMesh::EMaterialFilterCriterion Criterion);
/*!

*/
			Void Material_ClearFilters();
/*!

*/
			Void Material_UVEditor_SetIsRotation(Boolean IsRotation);
/*!

*/
			Void Material_UVEditor_SetIsScale(Boolean IsScale);
/*!

*/
			Void Material_UVEditor_SetIsScale1D(Boolean IsScale);
/*!

*/
			Void Material_UVEditor_Open(Ident MaterialId,CMlQuad LocationQuad);
/*!

*/
			Void Material_UVEditor_Close();
/*!

*/
			Boolean Material_UVEditor_IsRunning();
/*!

*/
			Void Material_UVEditor_SetMode(CEditorMesh::EUVEditorMode Mode);
/*!

*/
			CEditorMesh::EUVEditorMode Material_UVEditor_GetMode();
/*!

*/
			Void Material_UVEditor_SetProjectionType(CEditorMesh::EUVEditorProjectionType ProjectionType);
/*!

*/
			Boolean Material_IsGameMaterial();
/*!

*/
			Boolean Material_IsCustomLinkFull(Ident MaterialId);
/*!

*/
			Void Material_UVEditor_Apply();
/*!

*/
			Void Material_CopyMaterial(Ident SetHandle);
/*!

*/
			Void Material_PasteMaterial(Ident SetHandle);
/*!

*/
	const	Integer Material_Atlas_SelectedSubTexIndex;
/*!

*/
	const	CEditorMesh::EInteraction CurrentInteraction;
/*!

*/
			Void Interaction_Close();
/*!

*/
			Void Interaction_SetPreview(Ident SetToPreview);
/*!

*/
	const	Integer CreationElemsCount;
/*!

*/
			Boolean Interaction_StartCreation(Ident CreationSetHandle,CEditorMesh::EElemType ElemType,Ident SetToPickFromHandle);
/*!

*/
			Void Interaction_Creation_GetElems(Ident ResultSetHandle);
/*!

*/
			Void Interaction_Creation_ClearParams();
/*!

*/
			Void Interaction_Creation_SetEdgesConstraint(CEditorMesh::EEdgesConstraint EdgesConstraint);
/*!

*/
			Void Interaction_Creation_SetAutoMerge(Boolean AutoMerge);
/*!

*/
			Boolean Interaction_StartPaste();
/*!

*/
			Boolean Interaction_StartBlocTransformation(Ident TransformationSetHandle);
/*!

*/
			Boolean Interaction_StartCurve2D(Ident BordersSetHandle);
/*!

*/
			Void Interaction_CloseCurve2D(Boolean CanDoCurve2D);
/*!

*/
			Boolean Interaction_StartPick(CEditorMesh::EElemType ElemType,Ident SetToPickFrom);
/*!

*/
			Boolean Interaction_StartPickJoint();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Base(CEditorMesh::EElemType ElemType);
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Creation();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Delete();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Select(Ident SelectionSetHandle);
/*!

*/
			Void Interaction_CloseVoxelPickDrag_Select();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Pick();
/*!

*/
			Void Interaction_CloseVoxelPickDrag_Pick();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_SelectTranslation();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_SelectRotation();
/*!

*/
			Boolean Interaction_StartVoxelPickDrag_Paste();
/*!

*/
			Void CutVoxels();
/*!

*/
			Void CopyVoxels();
/*!

*/
			Boolean Interaction_StartMerge(Ident MergeSetHandle);
/*!

*/
			Boolean Interaction_StartMirror(Ident SetHandle);
/*!

*/
			Void Interaction_Selection_ClearParams();
/*!

*/
			Void Interaction_Selection_SetUseParts(Boolean UseParts);
/*!

*/
			Void Interaction_Selection_SetCanEnterLeaf(Boolean CanEnterLeaf);
/*!

*/
			Boolean Interaction_StartSelection(Ident SelectionSetHandle,CEditorMesh::EElemType ElemType,Ident SelectionSetToPickFrom,Boolean IsFromALayer,Boolean AllowDoubleClick);
/*!

*/
			Void Interaction_CloseSelection();
/*!

*/
			Boolean Interaction_StartTranslation(Ident TranslationSetHandle);
/*!

*/
			Boolean Interaction_StartPickTranslation(Ident TranslationSetHandle);
/*!

*/
			Boolean Interaction_StartRotation(Ident RotationSetHandle);
/*!

*/
			Boolean Interaction_StartPickRotation(Ident RotationSetHandle);
/*!

*/
			Void Interaction_Rotation_SetStep(Real RotationStep);
/*!

*/
			Boolean Interaction_StartPickScale(Ident ScalingSetHandle);
/*!

*/
			Void Interaction_Scale_SetStep(Real ScalingStep);
/*!

*/
			Boolean Interaction_StartSplit();
/*!

*/
			Void Display_HighlightSet(Ident SetHandle);
/*!

*/
			Void Display_ClearHighlighting();
/*!

*/
	const	Boolean Display_HideElemsByDistance_IsActive;
/*!

*/
			Integer Display_HideElemsByDistance_Distance;
/*!

*/
			Real Display_HideElemsByDistance_Opacity;
/*!

*/
			Void Display_HideElemsByDistance_Start(Ident SetHandle);
/*!

*/
			Void Display_HideElemsByDistance_Stop();
/*!

*/
			Void Display_HideMap();
/*!

*/
			Void Display_ShowMap();
/*!

*/
			Void MergeAllSuperposedElements(Ident SetHandle);
/*!

*/
	const	Ident SelectionSet;
/*!

*/
			Void Selection_Undo();
/*!

*/
			Void Selection_Redo();
/*!

*/
			Void Selection_Invert();
/*!

*/
			Void Selection_SelectAllByMaterial();
/*!

*/
			Ident SetOfElements_Create();
/*!

*/
			Void SetOfElements_CopyFrom(Ident DestinationSet,Ident SourceSet);
/*!

*/
			Void SetOfElements_Append(Ident DestinationSet,Ident SourceSet);
/*!

*/
			Void SetOfElements_Destroy(Ident SetHandle);
/*!

*/
			Void SetOfElements_Empty(Ident SetHandle);
/*!

*/
			Void SetOfElements_SetAllElements(Ident SetHandle);
/*!

*/
			Void SetOfElements_SetAllFaces(Ident SetHandle);
/*!

*/
			Void SetOfElements_DeleteElements(Ident SetHandle);
/*!

*/
			Void SetOfElements_DeleteElements(Ident SetHandle,Boolean Spread);
/*!

*/
			Boolean SetOfElements_HasHorizontalFaces(Ident SetHandle);
/*!

*/
			Boolean SetOfElements_HasVerticalFaces(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetElemsCount(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetVerticesCount(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetEdgesCount(Ident SetHandle);
/*!

*/
			Integer SetOfElements_GetFacesCount(Ident SetHandle);
/*!

*/
			Void ExtendSelectedSet(Ident SetHandle);
/*!

*/
			Boolean GetBordersSet(Ident SetHandle,Ident SetBordersHandle);
/*!

*/
			Void GetBordersVertexs(Ident SetHandle,Ident SetVertexHandle);
/*!

*/
			Void SelectionSet_SelectAll();
/*!

*/
			Void Curve2DPolygon(Ident FourVertexSetHandle,Ident Sethandle,Integer SubTexIndex);
/*!

*/
			Void Preview_Clear();
/*!

*/
			Void VoxelSpace_SetVec3(Vec3 Pos);
/*!

*/
			Integer VoxelSpace_GetVoxelsCount();
/*!

*/
			Void VoxelSpace_SelectAll();
/*!

*/
			Void VoxelSpace_DeleteOneVoxel();
/*!

*/
			Void VoxelSpace_DeleteSelection();
/*!

*/
			Void VoxelSpace_ApplyMaterialToVoxel();
/*!

*/
			Void VoxelSpace_GenerateMesh();
/*!

*/
			Vec3 VoxelSpaceCenter;
/*!

*/
			Real VoxelSpaceStep;
/*!

*/
			Boolean VoxelSpaceIsInteractive;
/*!

*/
			Void SetOfElements_ProjectOnPlane(Ident SetHandle);
/*!

*/
			Void SetOfElements_ProjectOnGround(Ident SetHandle,Real Height);
/*!

*/
			Void SetOfElements_SplitEdgeWithVertex(Ident SetHandle);
/*!

*/
			Void SetOfElements_CollapseEdgeWithVertex(Ident SetHandle);
/*!

*/
			Void SetOfElements_Subdivide(Ident SetHandle);
/*!

*/
			Void SetOfElements_Subdivide_Interpolation(Ident SetHandle);
/*!

*/
			Void SetOfVertices_DrawCircle(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawDisc(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawCircle(Ident CenterSetHandle,Vec3 PointOnCircle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawIcosahedron(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawIcosahedron(Ident CenterSetHandle,Vec3 PointOnCircle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawIcosahedricSphere(Ident InputSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_DrawPoly(Ident InputSetHandle,Ident ResultSetHandle,Integer VerticesCount);
/*!

*/
			Void SetOfVertices_DrawPoly(Ident CenterSetHandle,Vec3 PointOnPoly,Ident ResultSetHandle,Integer VerticesCount);
/*!

*/
			Void SetOfVertices_DrawSpline(Ident ControlSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfVertices_Weld(Ident VerticesSetHandle);
/*!

*/
			Void SetOfVertices_DrawBox(Ident ControlSetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfEdges_Fill(Ident SetHandle);
/*!

*/
			Void SetOfEdges_Flip(Ident SetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfEdges_BorderExpand(Ident SetHandle);
/*!

*/
			Void SetOfOneEdge_FaceLoopExpand(Ident SetHandle);
/*!

*/
			Void SetOfOneEdge_EdgeLoopExpand(Ident SetHandle);
/*!

*/
			Void SetOfOneFace_CutHole(Ident FaceSetHandle,Ident EdgesSetHandle);
/*!

*/
			Void SetOfFaces_Extrude(Ident SetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfFaces_QuadsToTriangles(Ident SetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfFaces_TrianglesToQuads(Ident SetHandle,Ident ResultSetHandle);
/*!

*/
			Void SetOfFaces_ApplyMaterial(Ident SetHandle,Ident MaterialId);
/*!

*/
			Void SetOfFaces_PlanarExpand(Ident FacesSetHandle);
/*!

*/
			Void SetOfFaces_ChangeOrientation(Ident FacesSetHandle);
/*!

*/
	const	Array<Text> PrefabNames;
/*!

*/
	const	Integer PrefabNamesUpdateId;
/*!

*/
			Integer PrefabListCurrentPage;
/*!

*/
			Integer Prefab_TotalNb;
/*!

*/
			Void Prefabs_Reload();
/*!

*/
			Void Prefab_Export();
/*!

*/
			Void Prefab_Import(Integer PrefabIndex);
/*!

*/
			Boolean Parts_CanMergeParts();
/*!

*/
			Boolean Parts_CanGroupParts();
/*!

*/
			Boolean Parts_CanUngroupParts();
/*!

*/
			Int3 Parts_GetOpsState();
/*!

*/
			Void Parts_MergeSelectedParts();
/*!

*/
			Void Parts_Group();
/*!

*/
			Void Parts_UngroupSelectedParts();
/*!

*/
			Void Cut();
/*!

*/
			Void Copy();
/*!

*/
			Void AddUndoState();
/*!

*/
			Boolean AutoSave(Text FileName);
/*!

*/
	const	Array<CEditorEvent> PendingEvents;
/*!

*/
			Boolean MustClearLastSaveBuffer;
/*!

*/
	const	Boolean IsExperimental;
/*!

*/
			CEditorMesh::ETitleCoreType GetTitleCoreType();
};

/*!
* \brief Documentation for class CEditorEditor
*
* Supported declare modes :
* - Metadata
*/
class CEditorEditor : public CEditorBase {
public :
/*!

*/
			Void Bindings_AddContext(Text ContextName);
/*!

*/
			Void Bindings_AddBinding(Text ContextName,Text BindingScriptId,Text BindingDisplayName);
/*!

*/
			Void Bindings_RemoveContext(Text ContextName);
/*!

*/
			Void Bindings_RemoveBinding(Text ContextName,Text BindingName);
/*!

*/
			Void Bindings_RequestInput(Text ContextName,Text BindingName);
/*!

*/
	const	Boolean Bindings_RequestInput_Done;
/*!

*/
			Void Bindings_SetBindingScriptId(Text ContextName,Text BindingScriptId,Text NewBindingScriptId);
/*!

*/
			Void Bindings_SetBindingDisplayName(Text ContextName,Text BindingScriptId,Text BindingDisplayName);
/*!

*/
			Void Bindings_SetContextName(Text ContextName,Text NewContextName);
/*!

*/
	const	Array<Text> BindingContexts;
/*!

*/
			Void Bindings_GetContextBindings(Text ContextName);
/*!

*/
	const	Array<Text> RequestedContextBindings;
/*!

*/
			Text Bindings_GetBindingActionName(Text ContextName,Text BindingName);
/*!

*/
			Text Bindings_GetBindingDisplayName(Text ContextName,Text BindingName);
/*!

*/
	const	Array<CEditorEvent> PendingEvents;
};

/*!
* \brief Documentation for class CEditorMediaTracker
*/
class CEditorMediaTracker : public CEditorPluginAPI {
public :
	/*!
	
	*/
	enum EMediaTrackerBlockType {
		Ghost,
		CameraCustom,
		CameraPath,
		Time,
		FxColors,
		Sound,
		Fog,
		TransitionFade,
		CameraEffectShake,
		CameraEffectScript,
		Stereo3d,
		DOF,
		ToneMapping,
		BloomHdr,
		DirtyLens,
		ColorGrading,
		FxCameraBlend,
		MusicEffect,
		TimeSpeed,
		TextBlock,
		Image,
		ColoringCapturable,
		ColoringBase,
		CameraGame,
		Trails,
		Manialink,
		EditingCut,
		CamFxInertialTracking,
		VehicleLight,
		Interface,
		Triangles2D,
		Triangles3D,
		CameraOrbital,
	};
	/*!
	
	*/
	enum EMediaTrackerCopyType {
		None,
		Key,
		Block,
	};
	/*!
	
	*/
	enum EMediaTrackerPasteType {
		None,
		KeyInfo,
		NewKey,
		BlockCurrentTrack,
		BlockNewTrack,
	};
	/*!
	
	*/
	enum EMediaTrackerGhostRef {
		Author,
		Ghost1,
		Ghost2,
		Ghost3,
	};
/*!

*/
			Real CurrentTimer;
/*!

*/
			Boolean UseOrbitalInsteadOfFreeCam;
/*!

*/
			Boolean UseClipCamWhenAvailable;
/*!

*/
			Boolean CanUseClipCam;
/*!

*/
			Real PlaySpeed;
/*!

*/
			Real CameraSpeed;
/*!

*/
			Real ClipConditionValue;
/*!

*/
			Void TimePlay();
/*!

*/
			Void TimeStop();
/*!

*/
			Void TimeToggle();
/*!

*/
			Void Rewind();
/*!

*/
			Void Quit();
/*!

*/
			Void UpdatePropertyListReadOnly();
/*!

*/
			Void CreateBlock();
/*!

*/
			Void CreateKey();
/*!

*/
			Void ToggleTriggersMode();
/*!

*/
			Void CreateClip();
/*!

*/
			Void RemoveClip();
/*!

*/
			Void Undo();
/*!

*/
			Void Redo();
/*!

*/
			Void ImportClip();
/*!

*/
			Void ExportClip();
/*!

*/
			Void ImportGhosts();
/*!

*/
			Void ToggleRecordGhostMode();
/*!

*/
			Void ShootVideo();
/*!

*/
			Void ShootScreen();
/*!

*/
			Void ComputeShadows();
/*!

*/
			Void ToggleDisplayPlayerNames();
/*!

*/
			Void InformInterfaceIsHidden();
/*!

*/
			Void ToggleGhostRef();
/*!

*/
			Void StopGhostRefPreview();
/*!

*/
			Void ToggleClipCondition();
/*!

*/
			Void Copy();
/*!

*/
			Void Paste();
/*!

*/
			Void Cut();
/*!

*/
			Void DuplicateTrack();
/*!

*/
			Void SplitBlock();
/*!

*/
			Void ToggleAlwaysShowTriggerZone();
/*!

*/
			Void ResetTriggerZone();
/*!

*/
			Void RemoveAllTracks();
/*!

*/
	const	CMediaTrackerClip Clip;
/*!

*/
	const	CMediaTrackerClipGroup ClipGroup;
/*!

*/
	const	Array<CEditorEvent> PendingEvents;
/*!

*/
	const	Text PopUpMessage;
/*!

*/
	const	CEditorMediaTracker::EMediaTrackerBlockType EditMode;
/*!

*/
			Void SetClip(CMediaTrackerClip Clip);
/*!

*/
			Boolean IsPlaying();
/*!

*/
			Void SetCameraDrawRect(Vec2 Pos,Vec2 Size);
/*!

*/
			Integer GetSelectedClip();
/*!

*/
			Integer GetSelectedTrack();
/*!

*/
			Integer GetSelectedBlock();
/*!

*/
			Integer GetSelectedKey();
/*!

*/
			Void SelectItem(Integer Track,Integer Block,Integer Key);
/*!

*/
			Void CreateTrack(CEditorMediaTracker::EMediaTrackerBlockType Type);
/*!

*/
			Boolean CanCreateTrack(CEditorMediaTracker::EMediaTrackerBlockType Type);
/*!

*/
			Boolean IsKeyStartEnd(Integer Track,Integer Block,Integer Key);
/*!

*/
			Void RemoveTrack(Integer Track);
/*!

*/
			Void RemoveBlock(Integer Track,Integer Block);
/*!

*/
			Void RemoveKey(Integer Track,Integer Block,Integer Key);
/*!

*/
			Boolean CanRemoveAllKeys(Integer Track,Integer Block);
/*!

*/
			Void RemoveAllKeys(Integer Track,Integer Block);
/*!

*/
			Void SetProcessCamInputs(Boolean ProcessCamInputs);
/*!

*/
			Void ToolBarSetVisible(Boolean Visible);
/*!

*/
			Boolean IsTriggersModeOn();
/*!

*/
			Boolean IsRecordGhostModeOn();
/*!

*/
			Void SetTempHidePropertyList(Boolean TempHide);
/*!

*/
			Void SetClipName(Integer Index,Text Name);
/*!

*/
			Void SetTrackName(Integer Index,Text Name);
/*!

*/
			Void SetTrackIsCycling(CMediaTrackerTrack Track,Boolean IsCycling);
/*!

*/
			Void SetTrackIsKeepPlaying(CMediaTrackerTrack Track,Boolean IsKeepPlaying);
/*!

*/
			Boolean GetTrackIsCycling(CMediaTrackerTrack Track);
/*!

*/
			Boolean GetTrackIsKeepPlaying(CMediaTrackerTrack Track);
/*!

*/
			Void SetStartIsCycling(CMediaTrackerTrack Track);
/*!

*/
			Void SetStopIsCycling(CMediaTrackerTrack Track);
/*!

*/
			Real GetStartIsCycling(CMediaTrackerTrack Track);
/*!

*/
			Real GetStopIsCycling(CMediaTrackerTrack Track);
/*!

*/
			Text GetGhostRefName();
/*!

*/
			Text GetClipConditionName();
/*!

*/
			Boolean HasClipCondition();
/*!

*/
			Real GetTimeLimit();
/*!

*/
			Void SetTimer(Text Time);
/*!

*/
			Void SetCurrentBlockStart(Text Start);
/*!

*/
			Void SetCurrentBlockEnd(Text End);
/*!

*/
			CEditorMediaTracker::EMediaTrackerCopyType CanCopy();
/*!

*/
			CEditorMediaTracker::EMediaTrackerCopyType CanCut();
/*!

*/
			CEditorMediaTracker::EMediaTrackerPasteType CanPaste();
/*!

*/
			Boolean HasCopiedItem();
/*!

*/
			Boolean IsPropertyListReadOnlyAndVisible();
/*!

*/
			Void SelectGhostRef(CEditorMediaTracker::EMediaTrackerGhostRef Type);
/*!

*/
			Void DeleteGhostRef(CEditorMediaTracker::EMediaTrackerGhostRef Type);
/*!

*/
			Void RecordGhostRef(CEditorMediaTracker::EMediaTrackerGhostRef Type);
/*!

*/
			Boolean GhostRefExists(CEditorMediaTracker::EMediaTrackerGhostRef Type);
/*!

*/
			CEditorMediaTracker::EMediaTrackerGhostRef GetSelectedGhostRef();
/*!

*/
			Void StartGhostRefPreview(CEditorMediaTracker::EMediaTrackerGhostRef Type);
/*!

*/
			Void RemoveAllGhostTracksExcept(Integer Track);
/*!

*/
			Void RemoveAllCameraTracksExcept(Integer Track);
/*!

*/
			Boolean CanRemoveAllGhostTracks();
/*!

*/
			Boolean CanRemoveAllCameraTracks();
/*!

*/
			Boolean IsGhostRefPreview();
/*!

*/
			Void SetProfileTheme(Integer Theme);
/*!

*/
			Integer GetProfileTheme();
};

/*!
* \brief Documentation for class CEditorSkin
*/
class CEditorSkin : public CEditorPluginAPI {
public :
	/*!
	
	*/
	enum EPainterMode {
		NoOp,
		Fill,
		Brush,
		Sticker,
		Layer,
		BadgeSlots,
		Team,
	};
	/*!
	
	*/
	enum EPainterSolidType {
		Other,
		CarWithPilot,
		Pilot_Male,
		Pilot_Female,
		Helmet,
	};
	/*!
	
	*/
	enum EEditorSkin_IconType {
		Stickers,
		Brushs,
		Layers,
		SubObjects,
	};
/*!

*/
			Array<CImage> AllIcons;
/*!

*/
			Array<CEditorEvent> PendingEvents;
/*!

*/
			Array<Vec3> CustomColors;
/*!

*/
			CEditorSkin::EPainterMode PainterMode;
/*!

*/
			CEditorSkin::EPainterSolidType PainterSolidType;
/*!

*/
			Boolean IsTextEnabled;
/*!

*/
			Boolean IsPickingColor;
/*!

*/
			Boolean IsErasing;
/*!

*/
			Boolean IsUsingShininessOnly;
/*!

*/
			Boolean IsBrushNormal;
/*!

*/
			Boolean IsTextSymmetry;
/*!

*/
			Array<Integer> SubObjectsSelected;
/*!

*/
			Integer SubObjectsCount;
/*!

*/
			Array<Integer> LayersSelected;
/*!

*/
			Integer LayersCount;
/*!

*/
			Array<Integer> StickersSelected;
/*!

*/
			Integer StickersCount;
/*!

*/
			Array<Integer> BrushsSelected;
/*!

*/
			Integer BrushsCount;
/*!

*/
			Array<Integer> SubFolderElemSelected;
/*!

*/
			Integer CurSubFolderElemCount;
/*!

*/
			Real Transparency;
/*!

*/
			Real Scale;
/*!

*/
			Real Rough;
/*!

*/
			Real Metal;
/*!

*/
			Vec3 Color;
/*!

*/
			Integer EditionLayersCount;
/*!

*/
			Boolean IsEditingLayer;
/*!

*/
			Integer EditionLayerSelected;
/*!

*/
			Integer SubObjectHovered;
/*!

*/
			Array<Integer> CurrentLayerSubObjectsSelected;
/*!

*/
			Boolean CanUndo;
/*!

*/
			Boolean CanRedo;
/*!

*/
			Text TextToCreateBitmap;
/*!

*/
			Boolean IsFillWithReplacement;
/*!

*/
			Text SkinName;
/*!

*/
			Boolean IsSkinHelmetOk;
/*!

*/
			Boolean IsCameraButtonOn;
/*!

*/
			Void ToggleIsTextEnabled();
/*!

*/
			Void ToggleIsPickingColor();
/*!

*/
			Void TogglePaintSymMode();
/*!

*/
			Void EditCurrentLayerSelected();
/*!

*/
			Void AddAndEditLayer();
/*!

*/
			Void CloseEditSelectedLayer();
/*!

*/
			Void MoveSelectedLayerUp();
/*!

*/
			Void MoveSelectedLayerDown();
/*!

*/
			Void DeleteSelectedLayer();
/*!

*/
			Void Undo();
/*!

*/
			Void Redo();
/*!

*/
			Void ExportSkin();
/*!

*/
			Void AlignBrushSticker();
/*!

*/
			Void AskSwitchEditedNodType();
/*!

*/
			Void ToggleHelper();
/*!

*/
			Void ToggleLight();
/*!

*/
			Void ExportLayerEdition();
/*!

*/
			Void ImportLayerEdition();
/*!

*/
			CImage GetAllIconFromId(Integer Index,CEditorSkin::EEditorSkin_IconType IconType);
/*!

*/
			CImage GetSubFolderIconFromId(Integer FolderIndex,Integer ElemIndex,CEditorSkin::EEditorSkin_IconType IconType);
/*!

*/
			Text GetLayerNameFromIndex(Integer Index);
/*!

*/
			Boolean GetLayerVisibleFromIndex(Integer Index);
/*!

*/
			Void SetLayerVisibleFromIndex(Boolean IsVisible,Integer Index);
/*!

*/
			Boolean SetPainterMode(CEditorSkin::EPainterMode Mode);
/*!

*/
			Integer GetSubObjectMaxPage(Integer NbPerPage);
/*!

*/
			Integer GetMainFrameMaxPage(Integer NbPerPage);
/*!

*/
			Void OnLayerSelected(Integer CurrentPage,Integer Index);
/*!

*/
			Void OnStickerSelected(Integer CurrentPage,Integer Index);
/*!

*/
			Void OnBrushSelected(Integer CurrentPage,Integer Index);
/*!

*/
			Void OnSubFolderElemSelected(Integer SubFolderCurrentPage,Integer ElemIndex);
/*!

*/
			Void SetCurrentLayerSelectedName(Text Name);
/*!

*/
			Void AddScale(Real Delta);
/*!

*/
			Void AddAngle(Real DeltaRad);
/*!

*/
			Void SetSubObjectIndexForLayer(Integer SubObjectIndex,Integer LayerIndex,Boolean ResetFirst);
/*!

*/
			Boolean IsElemAtScriptIndexFolder(Integer ScriptIndex,CEditorSkin::EEditorSkin_IconType IconType);
/*!

*/
			Text GetFolderNameFromScriptIndex(Integer ScriptIndex,CEditorSkin::EEditorSkin_IconType IconType);
/*!

*/
			Boolean IsCtrlDown();
/*!

*/
			Text GetSubObjectNameFromIndex(Integer ScriptIndex);
/*!

*/
			Void OpenMediaFolder(Text SubFolderPath);
/*!

*/
			Void ReloadResources(Boolean forSubObjects);
};

/*!
* \brief Documentation for class CUIConfigMarker
*/
class CUIConfigMarker : public CNod {
public :
	/*!
	
	*/
	enum EAnchorType {
		Invalid,
		Position,
		Player,
		Entity,
		Landmark,
		GhostInstance,
	};
	/*!
	
	*/
	enum EMiniMapVisibility {
		Never,
		Always,
		WhenInFrame,
	};
	/*!
	
	*/
	enum EHudVisibility {
		Never,
		Always,
		WhenInFrustum,
		WhenVisible,
		WhenInMiddleOfScreen,
	};
/*!

*/
	const	CUIConfigMarker::EAnchorType Type;
/*!

*/
			Boolean IsTurning;
/*!

*/
			Boolean ShowArmor;
/*!

*/
			Text Label;
/*!

*/
			Vec3 Box;
/*!

*/
			Text Icon;
/*!

*/
			Vec3 Color;
/*!

*/
			Text ImageUrl;
/*!

*/
			Text ManialinkFrameId;
/*!

*/
			Real DistMax;
/*!

*/
			CUIConfigMarker::EMiniMapVisibility MiniMapVisibility;
/*!

*/
			CUIConfigMarker::EHudVisibility HudVisibility;
/*!

*/
			Real Gauge;
};

/*!
* \brief Documentation for class CMapLandmark
*
* Supported declare modes :
* - Local
* - Metadata
*/
class CMapLandmark : public CNod {
public :
/*!
Use this instead of Id when filling CUIConfig.MarkersXML
*/
	const	Ident MarkerId;
/*!

*/
	const	Text Tag;
/*!

*/
	const	Integer Order;
/*!

*/
	const	Vec3 Position;
/*!

*/
	const	CMapSector Sector;
/*!

*/
	const	CMapWaypoint Waypoint;
/*!

*/
	const	CMapSpawn PlayerSpawn;
/*!

*/
	const	CMapBotPath BotPath;
/*!

*/
	const	CMapBotSpawn BotSpawn;
/*!

*/
	const	CMapObjectAnchor ObjectAnchor;
};

/*!
* \brief UIConfig Event
*
* Supported declare modes :
* - Local
*/
class CUIConfigEvent : public CBaseEvent {
public :
	/*!
	
	*/
	enum EType {
		Unknown,
		OnModuleCustomEvent,
		OnModuleShowRequest,
		OnModuleHideRequest,
		OnModuleStorePurchase,
		OnModuleInventoryDrop,
		OnModuleInventoryEquip,
		OnLayerCustomEvent,
	};
	/*!
	
	*/
	enum EModuleType {
		Undefined,
		Hud,
		Inventory,
		Store,
		ScoresTable,
		Equipment,
		MenuBase,
		MenuPage,
		Chrono,
		SpeedMeter,
		PlayerState,
		TeamState,
	};
/*!

*/
	const	CUIConfigEvent::EType Type;
/*!

*/
	const	CUIConfig UI;
/*!

*/
	const	CUIConfigEvent::EModuleType ModuleType;
/*!

*/
	const	Text Param1;
/*!

*/
	const	Array<Text> Param2;
/*!

*/
	const	CUILayer CustomEventLayer;
/*!

*/
	const	Text CustomEventType;
/*!

*/
	const	Array<Text> CustomEventData;
/*!

*/
	const	Text ItemUrl;
/*!

*/
	const	Integer Quantity;
};

/*!
* \brief Documentation for class CServerInfo
*/
class CServerInfo : public CNod {
public :
/*!

*/
	const	Text ServerName;
/*!

*/
	const	Text ServerLogin;
/*!

*/
	const	Text JoinLink;
/*!

*/
	const	Text Comment;
/*!

*/
	const	Text ServerVersionBuild;
/*!

*/
	const	Integer PlayerCount;
/*!

*/
	const	Integer MaxPlayerCount;
/*!

*/
	const	Integer SpectatorCount;
/*!

*/
	const	Integer MaxSpectatorCount;
/*!

*/
	const	Real PlayersLevelMin;
/*!

*/
	const	Real PlayersLevelAvg;
/*!

*/
	const	Real PlayersLevelMax;
/*!

*/
	const	Integer ServerLevel;
/*!

*/
	const	Text ServerLevelText;
/*!

*/
	const	Text ModeName;
/*!

*/
	const	Real LadderServerLimitMax;
/*!

*/
	const	Real LadderServerLimitMin;
/*!

*/
	const	Array<Text> PlayerNames;
/*!

*/
	const	Array<Text> ChallengeNames;
/*!

*/
	const	Array<Text> ChallengeIds;
/*!

*/
	const	Integer NbChallenges;
/*!

*/
	const	Boolean HasBuddies;
/*!

*/
	const	Boolean IsFavourite;
/*!

*/
	const	Boolean IsLobbyServer;
/*!

*/
	const	Boolean IsPrivate;
/*!

*/
	const	Boolean IsPrivateForSpectator;
/*!

*/
	const	Boolean IsMapDownloadAllowed;
/*!

*/
	const	Text SendToServerAfterMatchUrl;
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CXmlRpcEvent : public CBaseConstEvent {
public :
	/*!
	
	*/
	enum EType {
		Unknown,
		Callback,
		CallbackArray,
	};
/*!

*/
	const	CXmlRpcEvent::EType Type;
/*!

*/
	const	Text Param1;
/*!

*/
	const	Text Param2;
/*!

*/
	const	Text ParamArray1;
/*!

*/
	const	Array<Text> ParamArray2;
};

/*!
* \brief Documentation for class CModulePlaygroundHud
*/
class CModulePlaygroundHud : public CNod {
public :
/*!

*/
			CModulePlaygroundInventory Inventory;
/*!

*/
			CModulePlaygroundStore Store;
/*!

*/
			CModulePlaygroundScoresTable ScoresTable;
/*!

*/
			CModulePlaygroundChrono Chrono;
/*!

*/
			CModulePlaygroundSpeedMeter SpeedMeter;
/*!

*/
			CModulePlaygroundPlayerState PlayerState;
/*!

*/
			CModulePlaygroundTeamState TeamState;
/*!

*/
	const	Array<CModulePlayground> Modules;
/*!

*/
			Void SwitchContext(CPlayer Player,Text ContextName);
/*!

*/
			Void SetDefaultContext(CPlayer Player);
/*!

*/
			Ident RetrieveModuleId(Text ModuleName);
};

/*!
* \brief Task result containing a list of account trophy gain.
*/
class CTaskResult_AccountTrophyGainList : public CWebServicesTaskResult_AccountTrophyGainList {
public :
/*!
List of account trophy gain contained in this result.
*/
	const	Array<CAccountTrophyGain> AccountTrophyGainList;
};

/*!
* \brief Documentation for class CModeTurretManager
*/
class CModeTurretManager : public CNod {
public :
/*!

*/
			Void MapTurrets_Reset();
/*!

*/
			CModeTurret Turret_Create(Ident ModelId,Vec3 Position,Vec3 Direction,Integer Clan,CPlayer OwnerPlayer);
/*!

*/
			CModeTurret Turret_CreateWithOwner(Ident ModelId,Vec3 Position,Vec3 Direction,Vec3 Up,Integer Clan,Ident OwnerId);
/*!

*/
			CModeTurret Turret_CreateWithOwner(Ident ModelId,Vec3 Position,Vec3 Direction,Vec3 Up,Integer Clan,Ident OwnerId,Boolean AutoAimOn,Boolean AutoTriggerOn);
/*!

*/
			Vec3 Turret_GetPosition(CModeTurret Turret);
/*!

*/
			Void Turret_Destroy(CModeTurret Turret);
/*!

*/
			Void Turret_DestroyAll();
/*!

*/
			Void Turret_Activate(CModeTurret Turret);
/*!

*/
			Void Turret_Deactivate(CModeTurret Turret);
/*!

*/
			Void Turret_SetIsAutomatic(CModeTurret Turret,Boolean IsAuto);
/*!

*/
			Void Turret_Auto_SetAimAnticipation(CModeTurret Turret,Real AimAnticipationMs);
/*!

*/
			Void Turret_Auto_SetFirePeriod(CModeTurret Turret,Integer FirePeriodMs);
/*!

*/
			Void Turret_Auto_SetTargetDetectionFov(CModeTurret Turret,Real DectectionFOVDeg);
/*!

*/
			Void Turret_Auto_SetTargetDetectionRadius(CModeTurret Turret,Real DetectionRadius);
/*!

*/
			Void Turret_Manual_SetTargetPos(CModeTurret Turret,Vec3 TargetPos);
/*!

*/
			Void Turret_Manual_Fire(CModeTurret Turret);
/*!

*/
			Array<CModeTurret> Turrets;
};

/*!
* \brief Documentation for class CModeVehicleManager
*/
class CModeVehicleManager : public CNod {
public :
	/*!
	
	*/
	enum EArmorUse {
		Self,
		Group,
		Owner,
		Children,
		Mine,
	};
	/*!
	
	*/
	enum ESlotType {
		Driver,
		Passenger,
	};
/*!

*/
			Void MapVehicles_Reset();
/*!

*/
			Void DestroyAllVehicles();
/*!

*/
			CModeVehicle Vehicle_Create(Ident ModelId,Integer Clan,Integer Armor,CModeVehicleManager::EArmorUse ArmorUse,CMapSpawn Spawn);
/*!

*/
			CModeVehicle Vehicle_Create(Ident ModelId,Vec3 Offset,Integer Armor,CModeVehicleManager::EArmorUse ArmorUse,CModeVehicle Owner);
/*!

*/
			Void Vehicle_Destroy(CModeVehicle Vehicle);
/*!

*/
			Void Vehicle_Assign_AutoPilot(CModeVehicle Vehicle,Text ModelName);
/*!

*/
			Void Vehicle_Assign_AutoPilot(CModeVehicle Vehicle,Text ModelName,Boolean LoopPath);
/*!

*/
			Void Vehicle_SetTrailVisible(CModeVehicle Vehicle,Boolean IsVisible);
/*!

*/
			Void Vehicle_SetShieldVisible(CModeVehicle Vehicle,Boolean IsVisible);
/*!

*/
			Integer VehicleModel_GetSlotsCount(Ident ModelId,CModeVehicleManager::ESlotType SlotType);
/*!

*/
			Array<CModeVehicle> Vehicles;
};

/*!
* \brief Documentation for class CActionManager
*/
class CActionManager : public CNod {
public :
	/*!
	
	*/
	enum EActionSlot {
		Slot_A,
		Slot_B,
		Slot_C,
		Slot_D,
		Slot_E,
		Slot_F,
		Slot_G,
		Slot_H,
	};
/*!

*/
			CActionInterface Action_GetState(CPlayer Player,CActionManager::EActionSlot Slot);
/*!

*/
			CActionInterface Action_GetState(CModeVehicle Vehicle,Integer VehicleSlotIndex,CActionManager::EActionSlot Slot);
/*!

*/
			CActionInterface Action_GetState(CModeTurret Turret,CActionManager::EActionSlot Slot);
/*!

*/
			Array<CActionInterface> Actions;
};

/*!
* \brief API for ShootMania bots
*/
class CSmPlayerDriver : public CNod {
public :
	/*!
	
	*/
	enum ESmDriverBehaviour {
		Static,
		Turret,
		Scripted,
		IA,
		Patrol,
		Escape,
		Saunter,
		Orbit,
		Follow,
	};
	/*!
	
	*/
	enum ESmDriverPathState {
		Static,
		None,
		Computing,
		Simple,
		Full,
		Incomplete,
		InFlock,
	};
	/*!
	
	*/
	enum ESmDriverPatrolMode {
		OneTrip,
		BackAndForth,
		Loop,
	};
	/*!
	
	*/
	enum ESmAttackFilter {
		All,
		AllPlayers,
		AllBots,
		AllOpposite,
		OppositePlayers,
		OppositeBots,
		Nobody,
	};
/*!

*/
			CSmPlayerDriver::ESmDriverBehaviour Behaviour;
/*!

*/
			Boolean PursueTarget;
/*!

*/
			Real AggroRadius;
/*!

*/
			Real ShootRadius;
/*!

*/
			Real TargetMinDistance;
/*!

*/
			Real DisengageDistance;
/*!

*/
			Real PathSpeedCoef;
/*!

*/
			Real Accuracy;
/*!

*/
			Integer ReactionTime;
/*!

*/
			Integer ShootPeriodMin;
/*!

*/
			Integer ShootPeriodMax;
/*!

*/
			Boolean RocketAnticipation;
/*!
The field of view angle the driver uses to search for targets. Value in degrees.Values in range (0.000000-360.000000)
*/
			Real TargetDetectionFov;
/*!

*/
			CSmPlayerDriver::ESmAttackFilter AttackFilter;
/*!

*/
	const	CSmPlayer Target;
/*!

*/
	const	Boolean IsStuck;
/*!
PathFinding takes some time to compute and doesn't always reach the intended goal. The player will most probably reach the goal in the case CSmPlayerDriver::ESmDriverPathState::Full.
*/
	const	CSmPlayerDriver::ESmDriverPathState PathState;
/*!

*/
	const	CSmPlayer Owner;
/*!

*/
			Void Scripted_Move(Vec3 Goal);
/*!

*/
			Void Scripted_MoveDelta(Vec3 Delta);
/*!

*/
			Void Scripted_MoveAndAim(Vec3 Goal);
/*!

*/
			Void Scripted_MoveDeltaAndAim(Vec3 Delta);
/*!

*/
			Void Scripted_Aim(Vec3 Goal);
/*!

*/
			Void Scripted_AimDelta(Real DeltaYaw,Real DeltaPitch);
/*!
Same as Scripted_RequestInput(CSmMode::EActionInput::Movement).
*/
			Void Scripted_RequestAction();
/*!
Same as Scripted_RequestInput(CSmMode::EActionInput::Weapon). This has no effect when ForcedTarget is not Null.
*/
			Void Scripted_RequestGunTrigger();
/*!

*/
			Void Scripted_RequestInput(CSmMode::EActionInput Input);
/*!

*/
			CSmPlayerDriver::ESmDriverPatrolMode Patrol_Mode;
/*!
Note that CSmMode::SpawnPlayer and CSmMode::SpawnBotPlayer may reset this value to the spawn position.
*/
			Vec3 Escape_AnchorPoint;
/*!

*/
			Real Escape_DistanceSafe;
/*!

*/
			Real Escape_DistanceMinEscape;
/*!

*/
			Real Escape_DistanceMaxEscape;
/*!
Note that CSmMode::SpawnPlayer and CSmMode::SpawnBotPlayer may reset this value to the spawn position.
*/
			Vec3 Saunter_AnchorPoint;
/*!

*/
			Integer Saunter_BaseChillingTime;
/*!

*/
			Integer Saunter_ChillingTimeDelta;
/*!

*/
			Real Saunter_Radius;
/*!
Note that CSmMode::SpawnPlayer and CSmMode::SpawnBotPlayer may reset this value to the spawn position.
*/
			Vec3 Orbit_AnchorPoint;
/*!

*/
			Real Orbit_Radius;
/*!

*/
			Boolean Orbit_IsClockWise;
/*!

*/
			Boolean Scripted_ForceAimInMoveDir;
/*!

*/
			Vec3 Follow_Offset;
/*!

*/
			Boolean Follow_ForceAimInLeaderDir;
/*!

*/
			Boolean Follow_HasLeader;
/*!

*/
			CSmPlayer Follow_Leader;
/*!

*/
			Vec3 Follow_AnchorPoint;
/*!

*/
			CSmPlayer ForcedTarget;
/*!

*/
			Array<CSmPlayer> TargetsToAvoid;
/*!

*/
			Boolean PredictJump;
/*!

*/
			Boolean UsePathFinding;
/*!

*/
			CSmMode::EActionInput OnStuckInput;
/*!

*/
			Real MaxPathDivergence;
/*!
If larger than 0.0, this bot can attack destructible parts of the world.
*/
			Real TargetWorldRadius;
/*!
How much the driver value attacking the world rather than players. 0.0 for players only, 1.0 for world only, 0.5 for no preference.Values in range (0.000000-1.000000)
*/
			Real TargetWorldPriority;
/*!
How long the driver will try to chase its target after it can't see it, 0 to disable.
*/
			Integer LostTargetChaseDuration;
/*!
Flocking is a work in progress.
You need to fill this array and define a default behaviour for each member of the flock.
*/
			Array<CSmPlayerDriver> FlockPartners;
/*!
Flocking is a work in progress.
How far the driver see its neighbours.
*/
			Real FlockRadius;
/*!
Flocking is a work in progress.
The field of view angle the driver uses to see its neighbours. Value in degrees.Values in range (0.000000-360.000000)
*/
			Real FlockFov;
/*!
Flocking is a work in progress.
How much the driver values going towards its neighbours.
*/
			Real FlockCohesionWeight;
/*!
Flocking is a work in progress.
How much the driver values going the same direction as its neighbours.
*/
			Real FlockAlignmentWeight;
/*!
Flocking is a work in progress.
How much the driver values not hitting its neighbours.
*/
			Real FlockSeparationWeight;
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CBaseEvent : public CBaseConstEvent {
public :
/*!

*/
	const	Boolean HasBeenPassed;
/*!

*/
	const	Boolean HasBeenDiscarded;
};

/*!
* \brief Documentation for class CSmMapGate
*/
class CSmMapGate : public CNod {
public :
/*!

*/
			Integer Clan;
/*!

*/
			Boolean Automatic;
/*!

*/
			Boolean ManualClosed;
/*!

*/
	const	Boolean AutoClosed;
/*!

*/
			Boolean AutoIsActive;
/*!

*/
			Integer AutoCloseDelay;
/*!

*/
			Integer AutoOpenSpeed;
};

/*!
* \brief Documentation for class CSmMapGauge
*/
class CSmMapGauge : public CNod {
public :
/*!

*/
			Integer Clan;
/*!
Values in range (0.000000-1.000000)
*/
			Real ValueReal;
/*!

*/
			Integer Value;
/*!

*/
			Integer Max;
/*!

*/
			Integer Speed;
/*!

*/
			Boolean Captured;
};

/*!
* \brief Documentation for class CMapObjectAnchor
*/
class CMapObjectAnchor : public CNod {
public :
/*!

*/
	const	Text ItemName;
/*!

*/
	const	Ident ItemModelId;
};

/*!
* \brief Description of a race run.
*/
class CTmRaceResultNod : public CNod {
public :
	/*!
	
	*/
	enum ETmRaceResultCriteria {
		Time,
		Stunts,
		NbRespawns,
		CheckpointsProgress,
		None,
	};
/*!

*/
			Integer Time;
/*!

*/
			Integer Score;
/*!

*/
			Integer NbRespawns;
/*!

*/
			Array<Integer> Checkpoints;
/*!

*/
			Integer Compare(CTmRaceResultNod Other,CTmRaceResultNod::ETmRaceResultCriteria Criteria);
};

/*!
* \brief Documentation for class CModulePlaygroundTeamState
*/
class CModulePlaygroundTeamState : public CModulePlayground {
public :
/*!

*/
			Void Reset(CPlayer Player);
};

/*!
* \brief Documentation for class CModulePlaygroundPlayerState
*/
class CModulePlaygroundPlayerState : public CModulePlayground {
public :
/*!

*/
			Void Reset(CPlayer Player);
};

/*!
* \brief Documentation for class CModulePlaygroundSpeedMeter
*/
class CModulePlaygroundSpeedMeter : public CModulePlayground {
public :
/*!

*/
			Void Reset(CPlayer Player);
/*!

*/
			Void SetGlobalScale(Real Scale);
/*!

*/
			Void SetGaugeNumber(Integer Number);
/*!

*/
			Void SetGaugeAngle(Real Angle);
/*!

*/
			Void SetGaugeBGVisible(Boolean Visibility);
/*!

*/
			Void SetSpeedLineVisible(Boolean Visibility);
/*!

*/
			Void SetGaugeSpeedMax(Real Maximum);
/*!

*/
			Void SetSpeedValueScale(Real Scale);
/*!

*/
			Void SetSpeedUnitScale(Real Scale);
/*!

*/
			Void SetFooterUnitVisible(Boolean Visibility);
/*!

*/
			Void SetFooterLineVisible(Boolean Visibility);
/*!

*/
			Void SetDistanceVisible(Boolean Visibility);
/*!

*/
			Void SetDistanceFooterLineVisible(Boolean Visibility);
};

/*!
* \brief Documentation for class CModulePlaygroundChrono
*/
class CModulePlaygroundChrono : public CModulePlayground {
public :
/*!

*/
			Void StopChrono();
/*!

*/
			Void StartChrono();
/*!

*/
			Void Reset();
/*!

*/
			Void Reset(CPlayer Player);
};

/*!
* \brief Documentation for class CModulePlaygroundScoresTable
*/
class CModulePlaygroundScoresTable : public CModulePlayground {
public :
	/*!
	
	*/
	enum EColumnType {
		CustomString,
		CustomNatural,
		CustomInteger,
		CustomReal,
		CustomTime,
		Avatar,
		Name,
		ManiaStars,
		Tools,
		Tags,
		TMBestTime,
		TMPrevTime,
		TMBestLapTime,
		TMStunts,
		TMRespawns,
		TMCheckpoints,
		TMPoints,
		TMPrevRaceDeltaPoints,
		SMPoints,
		SMRoundPoints,
	};
	/*!
	
	*/
	enum EScoreSortOrder {
		Default,
		Name,
		LadderRanking,
		TMPoints,
		TMBestTime,
		TMBestLapTime,
		TMStunts,
		TMRespawns,
		TMCheckpoints,
		TMPrevTime,
		SMPoints,
		SMRoundPoints,
	};
/*!

*/
			Void SetFooterText(Text FooterText);
/*!

*/
			Void ResetCustomColumns(CScore Score);
/*!

*/
			Void ResetCustomColumns();
/*!

*/
			Void Scores_Sort(CModulePlaygroundScoresTable::EScoreSortOrder SortOrder);
/*!

*/
			Void SetColumnValue(CScore Score,Text ColumnId,Text ColumnValue);
/*!

*/
			Void SetColumnValue(CScore Score,Text ColumnId,Integer ColumnValue);
/*!

*/
			Void SetColumnValue(CScore Score,Text ColumnId,Real ColumnValue);
/*!

*/
			Void SetColumnVisibility(CModulePlaygroundScoresTable::EColumnType Type,Boolean Visibility);
/*!

*/
			Void SetColumnVisibility(Text ColumnId,Boolean Visibility);
/*!

*/
			Void SetColor(CScore Score,Vec3 Color);
/*!

*/
			Void ResetColor(CScore Score);
};

/*!
* \brief Documentation for class CModulePlaygroundInventory
*/
class CModulePlaygroundInventory : public CModulePlayground {
public :
/*!

*/
			Integer AddItem(CPlayer Player,Text Url,Integer Quantity);
/*!

*/
			Boolean AddAction(CPlayer Player,Text Url);
/*!

*/
			Integer RemoveInventoryItem(CPlayer Player,Text Url,Integer Quantity);
/*!

*/
			Integer GetInventoryItemQuantity(CPlayer Player,Text Url);
/*!

*/
			Boolean IsInventoryItemStored(CPlayer Player,Text Url);
/*!

*/
			Array<Text> GetStoredItemsList(CPlayer Player);
/*!

*/
			Array<Text> GetStoredActionsList(CPlayer Player);
};

/*!
* \brief An playground Store module.
*/
class CModulePlaygroundStore : public CModulePlayground {
public :
/*!

*/
			Void Reset();
/*!

*/
			Void Reset(CPlayer Player);
/*!

*/
			Void SetMoney(CPlayer Player,Integer Amount);
/*!

*/
			Integer GetMoney(CPlayer Player);
/*!

*/
			Boolean AddMoney(CPlayer Player,Integer Amount);
/*!

*/
			Boolean SubMoney(CPlayer Player,Integer Amount);
/*!

*/
			Void SetActionLevel(CPlayer Player,Text ActionUrl,Integer ActionLevel);
/*!

*/
			Integer GetActionLevel(CPlayer Player,Text ActionUrl);
/*!

*/
			Void SetItemCanBeBought(CPlayer Player,Text ActionUrl,Boolean CanBeBought);
/*!

*/
			Boolean GetItemCanBeBought(CPlayer Player,Text ActionUrl);
};

/*!
* \brief Documentation for class CModuleMenuFileBrowser
*/
class CModuleMenuFileBrowser : public CModuleMenuComponent {
public :
	/*!
	
	*/
	enum EFileType {
		Maps,
		Skins,
		Items,
		Blocks,
		Scripts,
		Images,
		Manialinks,
		Packs,
		Actions,
		Modules,
		Meshes,
		Replays,
	};
	/*!
	
	*/
	enum EFileAction {
		Select,
		Save,
		MultiSelect,
	};
/*!

*/
	const	Boolean HasFinished;
/*!

*/
	const	Array<Text> Selection;
/*!

*/
			Void SetFileType(CModuleMenuFileBrowser::EFileType FileType);
/*!

*/
			Void SetFileAction(CModuleMenuFileBrowser::EFileAction FileAction);
};

/*!
* \brief Represents a match-settings file
*/
class CMatchSettings : public CNod {
public :
/*!
Name of the file
*/
	const	Text Name;
/*!

*/
	const	Text FileName;
/*!

*/
			Text ScriptModeName;
/*!

*/
			Boolean ScriptModeName_Check(Text ScriptModeName);
/*!

*/
			Void ScriptModeName_Set(Text ScriptModeName);
/*!

*/
	const	Array<CMatchSettingsPlaylistItem> Playlist;
/*!

*/
			Boolean Playlist_FileExists(Text File);
/*!

*/
			Boolean Playlist_FileMatchesMode(Text File);
/*!

*/
			Void Playlist_Add(Text File);
/*!

*/
			Void Playlist_Remove(Integer Index);
/*!

*/
			Void Playlist_SwapUp(Integer Index);
/*!

*/
			Void Playlist_SwapDown(Integer Index);
};

/*!
* \brief API for Maniaplanet client scripts.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaAppBase : public CManiaApp {
public :
/*!

*/
	const	Array<CManiaAppEvent> PendingEvents;
};

/*!
* \brief Script API to create Pack files (can be Titlepack or plain ManiaCredited data).
*/
class CPackCreatorTitleInfo : public CNod {
public :
/*!

*/
	const	Ident TitleId;
/*!

*/
	const	Ident MakerTitleId;
/*!

*/
			Text DisplayName;
/*!

*/
			Text Description;
/*!

*/
			Text InfoUrl;
/*!

*/
			Text DownloadUrl;
/*!

*/
			Text TitleVersion;
/*!

*/
			Text AllowedClientTitleVersion;
/*!

*/
			Text BaseTitleIds;
/*!

*/
			Text ForcedPlayerModel;
/*!

*/
			Text Packaging_ImageFileName;
/*!

*/
			Text Packaging_LogosFileName;
/*!

*/
			Text Packaging_Group;
/*!
Can be an http://url or a ./path/in/title/datas/station.app.txt
*/
			Text Station_ManialinkUrl;
/*!

*/
			Text Menus_BgReplayFileName;
/*!

*/
			Text Menus_ManiaAppFileName;
/*!

*/
			Text Menus_MusicFileName;
/*!
Use  CGameManiaTitleEditionScriptAPI::SetTitleCampaign() to modify
*/
	const	Boolean Solo_HasCampaign;
/*!

*/
			Text Hud3dFontFileName;
/*!

*/
			Text HudDefaultModuleScriptName;
/*!

*/
			Text MusicFolder;
/*!

*/
			Text Editor_MusicFileName;
};

/*!
* \brief This is the client ManiaApp for game modes.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CManiaAppPlayground : public CManiaAppPlaygroundCommon {
public :
/*!
Send a custom event to the CMode script.
*/
			Void SendCustomEvent(Text Type,Array<Text> Data);
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CManiaAppPlaygroundEvent : public CManiaAppEvent {
public :
	/*!
	
	*/
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		PlaygroundScriptEvent,
		GhostAdded,
		RecordUpdated,
		RecordsUpdated,
		OnPlayerTriggerSpecial,
		OnPlayerTriggerWaypoint,
	};
	/*!
	
	*/
	enum GameplaySpecialType {
		None,
		Turbo,
		Turbo2,
		TurboRoulette,
		FreeWheeling,
		NoGrip,
		NoSteering,
		ForceAcceleration,
		Reset,
		SlowMotion,
		Bumper,
		Bumper2,
		ReactorBoost,
		Fragile,
		ReactorBoost2,
		XXX Null,
	};
	/*!
	
	*/
	enum GameplayTurboRoulette {
		TurboRoulette_None,
		TurboRoulette_1,
		TurboRoulette_2,
		TurboRoulette_3,
	};
/*!

*/
	const	CManiaAppPlaygroundEvent::Type PlaygroundType;
/*!

*/
	const	Text PlaygroundScriptEventType;
/*!

*/
	const	Array<Text> PlaygroundScriptEventData;
/*!

*/
	const	CGhost Ghost;
/*!

*/
	const	CManiaAppPlaygroundEvent::GameplaySpecialType GameplaySpecialType;
/*!

*/
	const	CManiaAppPlaygroundEvent::GameplayTurboRoulette GameplayTurboRoulette;
/*!

*/
	const	Boolean IsBoostUpElseDown;
/*!

*/
	const	Integer WaypointLandmarkIndex;
/*!

*/
	const	Integer RaceWaypointTime;
/*!

*/
	const	Integer RaceWaypointIndex;
/*!

*/
	const	Integer DiffWithBestRace;
/*!

*/
	const	Boolean DiffWithBestRace_IsValid;
/*!

*/
	const	Integer LapWaypointTime;
/*!

*/
	const	Integer LapWaypointIndex;
/*!

*/
	const	Integer DiffWithBestLap;
/*!

*/
	const	Boolean DiffWithBestLap_IsValid;
/*!

*/
	const	Boolean IsFinish;
/*!

*/
	const	Boolean IsNewLap;
};

/*!
* \brief Event concerning achievements.
*
* Supported declare modes :
* - Local
*/
class CAchievementsEvent : public CBaseConstEvent {
public :
	/*!
	
	*/
	enum EType {
		NewAchievement,
	};
/*!
Type of the event.
*/
	const	CAchievementsEvent::EType Type;
/*!
When Type is NewAchievement, this will be the new achievement
*/
	const	CAchievementsAchievement Achievement;
};

/*!
* \brief An achievement earned by a user.
*/
class CAchievementsAchievement : public CNod {
public :
/*!
User that earned the achievement.
*/
	const	Ident UserId;
/*!
Description of the achievement.
*/
	const	CAchievementsAchievementDesc AchievementDesc;
};

/*!
* \brief Achievement stat.
*/
class CAchievementsStat : public CNod {
public :
/*!
User that owns the stat.
*/
	const	Ident UserId;
/*!
Description of the stat.
*/
	const	CAchievementsStatDesc StatDesc;
/*!
Value of the stat.
*/
	const	Integer Value;
};

/*!
* \brief An achievement's description.
*/
class CAchievementsAchievementDesc : public CNod {
public :
/*!

*/
	const	Text TitleId;
/*!
Name of the achievement.
*/
	const	Text DisplayName;
/*!

*/
	const	Text Description;
/*!

*/
	const	Text IconUrl;
};

/*!
* \brief Achievement stat.
*/
class CAchievementsStatDesc : public CNod {
public :
/*!

*/
	const	Text TitleId;
/*!
Name of the stat.
*/
	const	Text DisplayName;
/*!

*/
	const	Text Description;
};

/*!
* \brief Documentation for class CMlGraphCurve
*/
class CMlGraphCurve : public CNod {
public :
/*!

*/
			Array<Vec2> Points;
/*!

*/
			Vec3 Color;
/*!

*/
			Void SortPoints();
/*!

*/
			Text Style;
/*!
Values in range (0.000000-50.000000)
*/
			Real Width;
};

/*!
* \brief Manialink filename entry.
*
* Supported declare modes :
* - Local
*/
class CMlFileEntry : public CMlEntry {
public :
/*!

*/
			Boolean OnlyUserFiles;
/*!

*/
			Void ClearFileNames();
/*!

*/
	const	Text FullFileName;
/*!

*/
	const	Text RelativeNameToRoot;
/*!

*/
	const	Text RelativeNameToTypeFolder;
};

/*!
* \brief Documentation for class CImage
*/
class CImage : public CNod {
public :
};

/*!
* \brief Documentation for class CParsingNode
*/
class CParsingNode : public CNod {
public :
/*!

*/
	const	Text Name;
/*!

*/
	const	Text TextContents;
/*!

*/
	const	Text TextRawContents;
/*!

*/
	const	Text TextRecursiveContents;
/*!

*/
	const	Array<CParsingNode> Children;
/*!

*/
			Text GetAttributeText(Text Name,Text DefaultValue);
/*!

*/
			Integer GetAttributeInteger(Text Name,Integer DefaultValue);
/*!

*/
			Real GetAttributeReal(Text Name,Real DefaultValue);
/*!

*/
			Boolean GetAttributeBoolean(Text Name,Boolean DefaultValue);
/*!

*/
			CParsingNode GetFirstChild(Text Name);
};

/*!
* \brief Documentation for class CMapGroup
*/
class CMapGroup : public CNod {
public :
/*!

*/
			Void IsUnlocked();
/*!

*/
	const	Array<CMapInfo> MapInfos;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_NadeoServicesMap : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CNadeoServicesMap
*/
class CNadeoServicesMap : public CNod {
public :
/*!

*/
	const	Text AuthorAccountId;
/*!

*/
	const	Text AuthorWebServicesUserId;
/*!

*/
	const	Text AuthorDisplayName;
/*!

*/
	const	Integer AuthorScore;
/*!

*/
	const	Integer BronzeScore;
/*!

*/
	const	Text CollectionName;
/*!

*/
	const	Text Filename;
/*!

*/
	const	Text FileName;
/*!

*/
	const	Text FileUrl;
/*!

*/
	const	Integer GoldScore;
/*!

*/
	const	Text Id;
/*!

*/
	const	Boolean IsPlayable;
/*!

*/
	const	Text Name;
/*!

*/
	const	Integer SilverScore;
/*!

*/
	const	Text SubmitterAccountId;
/*!

*/
	const	Text SubmitterWebServicesUserId;
/*!

*/
	const	Text ThumbnailUrl;
/*!

*/
	const	Integer TimeStamp;
/*!

*/
	const	Text Uid;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_NadeoServicesMapList : public CTaskResult {
public :
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_NadeoServicesSkin : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CNadeoServicesSkin
*/
class CNadeoServicesSkin : public CNod {
public :
/*!

*/
	const	Text Checksum;
/*!

*/
	const	Text CreatorAccountId;
/*!

*/
	const	Text CreatorWebServicesUserId;
/*!

*/
	const	Text CreatorDisplayName;
/*!

*/
	const	Text DisplayName;
/*!

*/
	const	Text Filename;
/*!

*/
	const	Text FileName;
/*!

*/
	const	Text FileUrl;
/*!

*/
	const	Text Id;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text ThumbnailUrl;
/*!

*/
	const	Integer TimeStamp;
/*!

*/
	const	Text Type;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_NadeoServicesSkinList : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CReplayInfo
*/
class CReplayInfo : public CNod {
public :
/*!

*/
	const	Text MapUid;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Path;
/*!

*/
	const	Text FileName;
};

/*!
* \brief A GameMode script.
*/
class CTaskResult_ModeInfo : public CNod {
public :
/*!
Name of the GameMode
*/
	const	Text Name;
/*!

*/
	const	Text Path;
/*!

*/
	const	Text Description;
/*!

*/
	const	Text Version;
/*!

*/
	const	Array<Text> CompatibleMapTypes;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_MapRecordList : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CMapRecord
*/
class CMapRecord : public CNod {
public :
/*!

*/
	const	Text AccountId;
/*!

*/
	const	Text WebServicesUserId;
/*!

*/
	const	Text MapId;
/*!

*/
	const	Ident MapUid;
/*!

*/
	const	Text ScopeType;
/*!

*/
	const	Text ScopeId;
/*!

*/
	const	Text GameMode;
/*!

*/
	const	Text GameModeCustomData;
/*!

*/
	const	Integer Score;
/*!

*/
	const	Integer Time;
/*!

*/
	const	Integer RespawnCount;
/*!

*/
	const	Integer Timestamp;
/*!

*/
	const	Integer MultiAsyncLevel;
/*!

*/
	const	Integer SkillPoints;
/*!

*/
	const	Text FileName;
/*!

*/
	const	Text ReplayUrl;
};

/*!
* \brief Documentation for class CHighScoreComparison
*/
class CHighScoreComparison : public CNod {
public :
/*!

*/
	const	CMapInfo MapInfo;
/*!

*/
	const	Text Login;
/*!

*/
	const	Integer RecordScore;
/*!

*/
	const	Integer RecordTime;
/*!

*/
	const	Integer RecordRespawnCount;
/*!

*/
	const	Integer RecordDate;
/*!

*/
	const	Text RecordDateString;
/*!

*/
	const	Integer RecordElapsedTime;
/*!

*/
	const	Integer RecordCount;
/*!

*/
	const	Text OpponentLogin;
/*!

*/
	const	Text OpponentDisplayName;
/*!

*/
	const	Text OpponentRecordUrl;
/*!

*/
	const	Integer OpponentRecordScore;
/*!

*/
	const	Integer OpponentRecordTime;
/*!

*/
	const	Integer OpponentRecordRespawnCount;
/*!

*/
	const	Integer OpponentRecordDate;
/*!

*/
	const	Text OpponentRecordDateString;
/*!

*/
	const	Integer OpponentRecordElapsedTime;
/*!

*/
	const	Integer OpponentRecordCount;
};

/*!
* \brief Documentation for class CHighScoreComparisonSummary
*/
class CHighScoreComparisonSummary : public CNod {
public :
/*!

*/
	const	Text Login;
/*!

*/
	const	Integer BestRecordCount;
/*!

*/
	const	Integer BestRecordLastDate;
/*!

*/
	const	Text BestRecordLastDateString;
/*!

*/
	const	Integer BestRecordElapsedTime;
/*!

*/
	const	Text OpponentLogin;
/*!

*/
	const	Text OpponentDisplayName;
/*!

*/
	const	Integer OpponentBestRecordCount;
/*!

*/
	const	Integer OpponentBestRecordLastDate;
/*!

*/
	const	Text OpponentBestRecordLastDateString;
/*!

*/
	const	Integer OpponentBestRecordElapsedTime;
};

/*!
* \brief Ranking item of a leaderboard.
*/
class CNaturalLeaderBoardInfo : public CNod {
public :
/*!
Rank.
*/
	const	Integer Rank;
/*!
UserId.
*/
	const	Ident UserId;
/*!
Login.
*/
	const	Text Login;
/*!
Display name.
*/
	const	Text DisplayName;
/*!
Score.
*/
	const	Integer Score;
/*!
FileName.
*/
	const	Text FileName;
/*!
ReplayUrl.
*/
	const	Text ReplayUrl;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_Season : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CSeason
*/
class CSeason : public CNod {
public :
/*!

*/
	const	Text CreatorAccountId;
/*!

*/
	const	Text CreatorWebServicesUserId;
/*!

*/
	const	Text GameMode;
/*!

*/
	const	Text GameModeCustomData;
/*!

*/
	const	Text MapRecordType;
/*!

*/
	const	Text Id;
/*!

*/
	const	Text Name;
/*!

*/
	const	Integer CreationTimeStamp;
/*!

*/
	const	Integer StartTimeStamp;
/*!

*/
	const	Integer EndTimeStamp;
/*!

*/
			Array<CSeasonMapInfo> MapInfoList;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_SeasonList : public CTaskResult {
public :
};

/*!
* \brief Ranking item of a leaderboard.
*/
class CRealLeaderBoardInfo : public CNod {
public :
/*!
Rank.
*/
	const	Integer Rank;
/*!
UserId.
*/
	const	Ident UserId;
/*!
Login.
*/
	const	Text Login;
/*!
Display name.
*/
	const	Text DisplayName;
/*!
Score.
*/
	const	Real Score;
/*!
FileName.
*/
	const	Text FileName;
/*!
ReplayUrl.
*/
	const	Text ReplayUrl;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_AccountTrophyLastYearSummary : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CAccountTrophyLastYearSummary
*/
class CAccountTrophyLastYearSummary : public CNod {
public :
/*!

*/
	const	Text AccountId;
/*!

*/
	const	Text WebServicesUserId;
/*!

*/
	const	Integer T1Count;
/*!

*/
	const	Integer T2Count;
/*!

*/
	const	Integer T3Count;
/*!

*/
	const	Integer T4Count;
/*!

*/
	const	Integer T5Count;
/*!

*/
	const	Integer T6Count;
/*!

*/
	const	Integer T7Count;
/*!

*/
	const	Integer T8Count;
/*!

*/
	const	Integer T9Count;
/*!

*/
	const	Integer TimeStamp;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_TrophySoloMedalAchievementSettings : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CTrophySoloMedalAchievementSettings
*/
class CTrophySoloMedalAchievementSettings : public CNod {
public :
/*!

*/
	const	Text Type;
/*!

*/
			CTrophySoloMedalAchievementLevelSettings AllBronzeLevelSettings;
/*!

*/
			CTrophySoloMedalAchievementLevelSettings AllSilverLevelSettings;
/*!

*/
			CTrophySoloMedalAchievementLevelSettings AllGoldLevelSettings;
/*!

*/
			CTrophySoloMedalAchievementLevelSettings AllAuthorLevelSettings;
};

/*!
* \brief Documentation for class CRankingsZone
*/
class CRankingsZone : public CNod {
public :
/*!

*/
	const	Text Id;
/*!

*/
	const	Text ParentId;
/*!

*/
	const	Text Name;
/*!

*/
	const	Text Path;
/*!

*/
	const	Text FullPath;
/*!

*/
	const	Text FlagUrl;
};

/*!
* \brief Vehicle or Character settings.
*/
class CVehicleSettings : public CNod {
public :
/*!

*/
	const	Text ModelDisplayName;
/*!

*/
	const	Text ModelName;
/*!
....
*/
	const	Text SkinName;
/*!

*/
	const	Text SkinUrl;
/*!
Values in range (0.100000-10.000000)
*/
			Real AnalogSensitivity;
/*!
Values in range (0.000000-0.250000)
*/
			Real AnalogDeadZone;
/*!

*/
			Boolean AnalogSteerV2;
/*!
Values in range (0.000000-2.000000)
*/
			Real RumbleIntensity;
/*!
Values in range (0.000000-1.000000)
*/
			Real CenterSpringIntensity;
};

/*!
* \brief UbiServices news.
*/
class CNetUbiServicesNews : public CNod {
public :
/*!

*/
	const	Ident Id;
/*!
A globally unique ID for the news item.
*/
	const	Text NewsId;
/*!
There is no predefined value, it is a contract between the producer and the consumer to define game specific.
*/
	const	Text Type;
/*!
Specifies where the news should be placed in-game.
*/
	const	Text Placement;
/*!
Localization string of the news, e.g. "en-US"
*/
	const	Text Locale;
/*!
Localized title of the news
*/
	const	Text Title;
/*!
Localized body of the news
*/
	const	Text Body;
/*!
Link to an image or video to be displayed with the news. Format of the media is placement specific.
*/
	const	Text MediaUrl;
/*!
MIME type of the media object to display.  e.g. "image/png" or "video/mp4"
*/
	const	Text MediaType;
/*!
The priority that should be given to that news.
*/
	const	Integer Priority;
/*!
The minimum time in seconds at which this news item should be displayed.
*/
	const	Integer DisplayTime;
/*!
Returns the date and (UTC) time at which the news was published.
*/
			Integer GetPublicationDate(Integer Month,Integer Day,Integer Hour,Integer Minute,Integer Second);
/*!
The number of links attached to this news. Links are mandatory for given types. For example, DLCOffer should have a mandatory storelink type link.
*/
	const	Integer LinksCount;
/*!
Returns Type, Param, ActionName and ActionDescription of the link. Type allows the game to correctly interpret param. The value may be game-specific but there are the following predefined types: "pstore" means that the param field contains the DLC ID related to the news content, "sstore" means that the param field contains an Offer ID related to an offer being available on the secondary store. "weblink" means that the param field should be an URL to a web page. Param defines the parameter value of the action. For a "pstore" type, value must be the DLC ID of the 1st party store (platform specific). For example, PS3 would look like "UP0001-NPUB90687_00-ACEMBERSVIDEO001", while on Xbox, it would look like: "0x555308796ea1e800". For a "sstore" type, value must be an Offer ID of the secondary store. This depends on the Secondary Store implementation of the game. For a "weblink" type, value must be a valid HTTP address. ActionName is The name of the action for tracking purposes. ActionDescription is the description of the action the game should display. The game must support default descriptions such as "Buy" for a store link.
*/
			Void GetLinkInfo(Integer LinkIndex,Text Type,Text Param,Text ActionName,Text ActionDescription);
};

/*!
* \brief Script API to create Packs (can be Titlepacks or plain ManiaCredited data), and generate new builds of these packs.
*/
class CPackCreator : public CNod {
public :
/*!
Register (or retreive) a package for the currently edited title.
*/
			Void RegisterPackForEditedTitle();
/*!

*/
	const	Boolean RegisterPack_IsInProgess;
/*!

*/
	const	CPackCreatorPack CurrentPack;
/*!
Start a new build for a pack, optionnaly a titlepack.
*/
			Ident Build_Begin(CPackCreatorPack Pack,CPackCreatorTitleInfo TitleInfo);
/*!

*/
			Void Build_AddFile(Ident BuildId,Text FileName);
/*!

*/
			Void Build_AddFolder(Ident BuildId,Text FolderName);
/*!

*/
			Void Build_AddFile(Ident BuildId,Text FileName,Boolean IsPublic,Boolean IsInternal,Boolean NoAutomaticDeps);
/*!

*/
			Void Build_AddFolder(Ident BuildId,Text FolderName,Boolean IsPublic,Boolean IsInternal,Boolean NoRecursion,Boolean NoAutomaticDeps);
/*!

*/
			Void Build_Generate(Ident BuildId,Boolean Upload);
/*!

*/
			Boolean Build_IsGenerated(Ident BuildId);
/*!

*/
			Text Build_ErrorMessage(Ident BuildId);
/*!

*/
			Void Build_End(Ident BuildId);
};

/*!
* \brief An event.
*/
class CNotificationsConsumerEvent : public CNod {
public :
	/*!
	
	*/
	enum EType {
		NewNotification,
		NotificationChanged,
	};
/*!
Type of the event.
*/
	const	CNotificationsConsumerEvent::EType Type;
/*!
Notification concerned by the event.
*/
	const	CNotificationsConsumerNotification Notification;
};

/*!
* \brief A Notification.
*/
class CNotificationsConsumerNotification : public CNod {
public :
	/*!
	
	*/
	enum ENotificationPriority {
		Memo,
		Notice,
		Alarm,
	};
/*!

*/
	const	Text Title;
/*!

*/
	const	Text Description;
/*!

*/
	const	Text ImageUrl;
/*!

*/
	const	CNotificationsConsumerNotification::ENotificationPriority Priority;
/*!

*/
	const	Boolean HasBeenRead;
/*!

*/
	const	Boolean HasBeenActivated;
/*!
The user has been displayed the Notification for a sufficient time.
*/
			Void SetRead();
/*!
The user has clicked on the Notification.
*/
			Void SetActivated();
};

/*!
* \brief Documentation for class CBadge
*/
class CBadge : public CNod {
public :
/*!

*/
			Vec3 PrimaryColor;
/*!

*/
			Text SkinName;
/*!

*/
			Text StickerSlot_Get(Text Slot);
/*!

*/
			Void StickerSlot_Set(Text Slot,Text Sticker);
/*!

*/
			Void StickerSlot_Clear();
/*!

*/
			Array<Text> Layers;
};

/*!
* \brief Documentation for class CMapEditorInventoryDirectory
*/
class CMapEditorInventoryDirectory : public CMapEditorInventoryNode {
public :
/*!

*/
	const	Array<CMapEditorInventoryNode> Children;
/*!

*/
	const	Boolean HasChildDirectory;
/*!

*/
	const	Boolean HasChildArticle;
};

/*!
* \brief Documentation for class CMapEditorInventoryNode
*/
class CMapEditorInventoryNode : public CNod {
public :
/*!

*/
	const	Text NodeName;
/*!

*/
	const	Boolean IsDirectory;
/*!

*/
	const	CMapEditorInventoryDirectory ParentNode;
/*!

*/
			CNod GetCollectorNod();
};

/*!
* \brief Documentation for class CMapEditorInventoryArticle
*/
class CMapEditorInventoryArticle : public CMapEditorInventoryNode {
public :
};

/*!
* \brief Documentation for class CCollector
*/
class CCollector : public CNod {
public :
/*!

*/
	const	Text Name;
/*!

*/
			Text PageName;
/*!

*/
			Integer InterfaceNumber;
/*!

*/
	const	CImage Icon;
/*!

*/
	const	Text SkinDirectory;
};

/*!
* \brief Documentation for class CBlockModelVariantGround
*/
class CBlockModelVariantGround : public CBlockModelVariant {
public :
};

/*!
* \brief Documentation for class CBlockModelVariantAir
*/
class CBlockModelVariantAir : public CBlockModelVariant {
public :
};

/*!
* \brief A 1-square-sized part of a block instance.
*/
class CBlockUnit : public CNod {
public :
/*!

*/
	const	Int3 AbsoluteOffset;
/*!

*/
	const	CBlockUnitModel BlockUnitModel;
/*!

*/
	const	CBlock Block;
};

/*!
* \brief Documentation for class CEditorBase
*
* Supported declare modes :
* - Metadata
*/
class CEditorBase : public CNod {
public :
};

/*!
* \brief Documentation for class CModuleMenuModel
*/
class CModuleMenuModel : public CNod {
public :
/*!

*/
			Array<CModuleMenuPageModel> Pages;
/*!

*/
			CModuleMenuPageModel AddPage(Text PageUrl);
/*!

*/
			Void AddLink(CModuleMenuPageModel ParentPage,CModuleMenuPageModel ChildPage);
/*!

*/
			Text MenuScript;
};

/*!
* \brief Documentation for class CModuleMenuPageModel
*/
class CModuleMenuPageModel : public CNod {
public :
/*!

*/
			Text ManialinkText;
};

/*!
* \brief Documentation for class CModulePlaygroundHudModel
*/
class CModulePlaygroundHudModel : public CNod {
public :
/*!

*/
			Ident ContextAdd(Text ContextName);
/*!

*/
			Ident ContextSetId(Ident ContextId,Text NewContextName);
/*!

*/
			Void ContextRemove(Ident ContextId);
/*!

*/
	const	Array<Ident> ContextsIds;
/*!

*/
	const	Array<CHudModule> SubModules;
/*!

*/
			CHudModule NewSubModule(Text ModulePath);
/*!

*/
			Void DeleteSubModule(CHudModule SubModule);
/*!

*/
			Boolean SubModuleIsContextActive(CHudModule SubModule,Ident ContextId);
/*!

*/
			Void SubModuleSetContextIsActive(CHudModule SubModule,Ident ContextId,Boolean IsActive);
/*!

*/
	const	Integer EditorContextIndex;
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CEditorPluginModuleEvent : public CManiaAppEvent {
public :
	/*!
	
	*/
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		Exit,
		FileNew,
		FileOpen,
		FileSave,
		FileSaveAs,
	};
/*!

*/
	const	CEditorPluginModuleEvent::Type Type;
/*!

*/
			Void Eat();
};

/*!
* \brief Documentation for class CEditorAsset
*
* Supported declare modes :
* - Metadata
*/
class CEditorAsset : public CEditorBase {
public :
};

/*!
* \brief An event
*
* Supported declare modes :
* - Local
*/
class CEditorEvent : public CManiaAppEvent {
public :
	/*!
	
	*/
	enum Type {
		LayerCustomEvent,
		KeyPress,
		(reserved),
		MenuNavigation,
		FileChanged,
		Exit,
		FileSave,
		OnUndo,
		OnRedo,
		OnSwitchedBack,
		CameraButtonOn,
		CameraButtonOff,
		VoxelUpdateMaterial,
		OpenUVEditor,
		CloseUVEditor,
		EnableUndo,
		DisableUndo,
		EnableRedo,
		DisableRedo,
		UpdateUI,
		UpdateSliders,
		UpdateMaterialsLibPage,
		MediaTrackerPopUp,
		HideUI,
		ShowUI,
		EnableFullScreen,
		DisableFullScreen,
		Autosave,
	};
/*!

*/
	const	CEditorEvent::Type Type;
};

/*!
* \brief Documentation for class CEditorPluginAPI
*/
class CEditorPluginAPI : public CNod {
public :
	/*!
	
	*/
	enum EEditorFileToolBar_QuadType {
		Quit,
		New,
		Open,
		SaveAs,
		Save,
		Import,
		Export,
		Close,
		Help,
	};
/*!

*/
			Void NewFile();
/*!

*/
			Void Undo();
/*!

*/
			Void Redo();
/*!

*/
			Void FileToolBarSendCmd(Text CmdName);
/*!

*/
			Boolean SetToolBarButtonVisible(CEditorPluginAPI::EEditorFileToolBar_QuadType Type);
};

/*!
* \brief Documentation for class CMediaTrackerClip
*/
class CMediaTrackerClip : public CNod {
public :
/*!

*/
			Text Name;
/*!

*/
	const	Array<CMediaTrackerTrack> Tracks;
/*!

*/
			Boolean StopWhenRespawn;
/*!

*/
			Boolean StopWhenLeave;
};

/*!
* \brief Documentation for class CMediaTrackerClipGroup
*/
class CMediaTrackerClipGroup : public CNod {
public :
/*!

*/
	const	Array<CMediaTrackerClip> Clips;
};

/*!
* \brief Documentation for class CMediaTrackerTrack
*/
class CMediaTrackerTrack : public CNod {
public :
/*!

*/
			Text Name;
/*!

*/
	const	Array<CMediaTrackerBlock> Blocks;
};

/*!
* \brief Documentation for class CMapSector
*/
class CMapSector : public CNod {
public :
/*!

*/
	const	Array<Ident> PlayersIds;
/*!

*/
	const	Text Tag;
};

/*!
* \brief Asynchronous task result.
*/
class CWebServicesTaskResult_AccountTrophyGainList : public CTaskResult {
public :
};

/*!
* \brief Documentation for class CAccountTrophyGain
*/
class CAccountTrophyGain : public CNod {
public :
/*!

*/
	const	Text AccountId;
/*!

*/
	const	Text WebServicesUserId;
/*!

*/
	const	Integer T1Count;
/*!

*/
	const	Integer T2Count;
/*!

*/
	const	Integer T3Count;
/*!

*/
	const	Integer T4Count;
/*!

*/
	const	Integer T5Count;
/*!

*/
	const	Integer T6Count;
/*!

*/
	const	Integer T7Count;
/*!

*/
	const	Integer T8Count;
/*!

*/
	const	Integer T9Count;
/*!

*/
	const	Integer TimeStamp;
};

/*!
* \brief Documentation for class CActionInterface
*/
class CActionInterface : public CNod {
public :
/*!

*/
	const	Integer Cooldown;
/*!

*/
	const	Integer CooldownStartTime;
/*!

*/
	const	Integer Energy;
/*!

*/
	const	Integer EnergyCost;
/*!

*/
	const	Integer EnergyMax;
};

/*!
* \brief Represents a map in the playlist of a matchsetting
*/
class CMatchSettingsPlaylistItem : public CNod {
public :
/*!
Name of the map
*/
	const	Text Name;
/*!
True if the file is found
*/
	const	Boolean FileExists;
};

/*!
* \brief API for Maniaplanet client scripts.
*
* Supported declare modes :
* - Local
* - Persistent
*/
class CBadgeEditor : public CManiaAppBase {
public :
/*!

*/
			Void Leave();
/*!

*/
			CBadge DisplayCurrentBadge;
/*!

*/
			Vec2 DisplayPosN;
/*!

*/
			Vec2 DisplaySize;
/*!

*/
			Real DisplayFoV;
/*!
Values in range (0.100000-10.000000)
*/
			Real CameraTransitionDuration;
/*!
Values in range (-10.000000-10.000000)
*/
			Real MeshRotation_MaxSpeed;
/*!
Values in range (0.100000-10.000000)
*/
			Real MeshRotation_Acceleration;
/*!

*/
			Ident DisplayCurrentMeshId;
/*!

*/
	const	Array<Ident> MeshIds;
/*!

*/
			Void MeshId_Next();
/*!

*/
			Void MeshId_Previous();
/*!

*/
	const	Array<CBadge> Badges;
/*!

*/
			CBadge BadgeCreate();
/*!

*/
			Void BadgeDestroy(CBadge Badge);
/*!

*/
			Void BadgeCopy(CBadge Source,CBadge Destination);
/*!

*/
			Void BadgeReadFromProfile(CBadge Badge,Ident UserId);
/*!

*/
			Void BadgeWriteToProfile(CBadge Badge,Ident UserId);
};

/*!
* \brief Documentation for class CSeasonMapInfo
*/
class CSeasonMapInfo : public CNod {
public :
/*!

*/
	const	Text MapId;
/*!

*/
	const	Ident MapUid;
/*!

*/
	const	Integer BronzeScore;
/*!

*/
	const	Integer SilverScore;
/*!

*/
	const	Integer GoldScore;
/*!

*/
	const	Integer AuthorScore;
/*!

*/
	const	Integer TimeStamp;
};

/*!
* \brief Documentation for class CTrophySoloMedalAchievementLevelSettings
*/
class CTrophySoloMedalAchievementLevelSettings : public CNod {
public :
/*!

*/
	const	Text Level;
/*!

*/
	const	Integer T1Count;
/*!

*/
	const	Integer T2Count;
/*!

*/
	const	Integer T3Count;
/*!

*/
	const	Integer T4Count;
/*!

*/
	const	Integer T5Count;
/*!

*/
	const	Integer T6Count;
/*!

*/
	const	Integer T7Count;
/*!

*/
	const	Integer T8Count;
/*!

*/
	const	Integer T9Count;
};

/*!
* \brief A pack
*/
class CPackCreatorPack : public CNod {
public :
/*!
PackId is the TitleId if the pack is a TitlePack.
*/
	const	Ident PackId;
/*!

*/
	const	Ident CreatorId;
/*!

*/
	const	Boolean IsTitlePack;
/*!

*/
			Void Recipients_Add(Text Login,Integer UseCost,Integer GetCost);
/*!

*/
			Void Recipients_Remove(Text Login);
/*!

*/
	const	Array<CPackCreatorRecipient> Recipients;
};

/*!
* \brief Documentation for class CBlockModelVariant
*/
class CBlockModelVariant : public CNod {
public :
/*!

*/
			Text Name;
/*!

*/
	const	Boolean IsAllUnderground;
/*!

*/
	const	Boolean IsPartUnderground;
/*!

*/
	const	Int3 Size;
/*!

*/
	const	Int3 OffsetBoundingBoxMin;
/*!

*/
	const	Int3 OffsetBoundingBoxMax;
/*!

*/
	const	Array<CBlockUnitModel> BlockUnitModels;
};

/*!
* \brief A 1-square-sized part of a block model.
*/
class CBlockUnitModel : public CNod {
public :
/*!

*/
	const	Int3 RelativeOffset;
/*!

*/
	const	Array<CBlockModelClip> Clips;
};

/*!
* \brief Documentation for class CHudModule
*/
class CHudModule : public CNod {
public :
/*!

*/
			Text ModuleName;
/*!

*/
			Real PosX;
/*!

*/
			Real PosY;
/*!

*/
			Real ZIndex;
/*!

*/
			Real Scale;
/*!

*/
	const	Text ModulePath;
};

/*!
* \brief Documentation for class CMediaTrackerBlock
*/
class CMediaTrackerBlock : public CNod {
public :
/*!

*/
			Real Start;
/*!

*/
			Real End;
/*!

*/
			Real GetKeyTime(Integer KeyIndex);
/*!

*/
			Integer GetKeysCount();
};

/*!
* \brief A recipient included in the bill for a Pack.
*/
class CPackCreatorRecipient : public CNod {
public :
/*!
Login of the recipient.
*/
	const	Text Login;
/*!
Cost to read the data (and see it ingame).
*/
	const	Integer GetCost;
/*!
Cost to use the in other creations.
*/
	const	Integer UseCost;
};

/*!
* \brief The model of a map block
*/
class CBlockModelClip : public CBlockModel {
public :
};

/*!
* \brief Standard mathematical operations, angles are in radians unless specified.
*/
namespace MathLib {

	const Real Pi = 3.14159;
	const Real Tau = 6.28319;
	/*! 
	*
	*/
	Integer Abs(Integer Argument1);
	/*! 
	*
	*/
	Real Abs(Real Argument1);
	/*! 
	*
	*/
	Real ToReal(Integer Argument1);
	/*! 
	* \brief Converts an angle from degrees to radians.
	* 
	*
	*/
	Real DegToRad(Real _Degree);
	/*! 
	* \brief Converts an angle from radians to degrees.
	* 
	*
	*/
	Real RadToDeg(Real _Radian);
	/*! 
	*
	*/
	Real Sin(Real Argument1);
	/*! 
	*
	*/
	Real Cos(Real Argument1);
	/*! 
	*
	*/
	Real Tan(Real Argument1);
	/*! 
	*
	*/
	Real Atan2(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Real Exp(Real Argument1);
	/*! 
	*
	*/
	Real Rand(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Real Rand(Real Argument1, Real Argument2, Integer Argument3);
	/*! 
	*
	*/
	Integer Rand(Integer Argument1, Integer Argument2);
	/*! 
	*
	*/
	Integer Rand(Integer Argument1, Integer Argument2, Integer Argument3);
	/*! 
	*
	*/
	Real NearestReal(Integer Argument1);
	/*! 
	*
	*/
	Integer NearestInteger(Real Argument1);
	/*! 
	*
	*/
	Integer FloorInteger(Real Argument1);
	/*! 
	*
	*/
	Integer TruncInteger(Real Argument1);
	/*! 
	*
	*/
	Integer CeilingInteger(Real Argument1);
	/*! 
	*
	*/
	Real Distance(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Real Distance(Vec2 Argument1, Vec2 Argument2);
	/*! 
	*
	*/
	Real Distance(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Real DotProduct(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Vec3 CrossProduct(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Real Angle(Vec3 Argument1, Vec3 Argument2);
	/*! 
	*
	*/
	Real OrientedAngle(Vec3 Argument1, Vec3 Argument2);
	/*! 
	* \brief Returns the smallest angle from A to B
	* 
	*
	*/
	Real Angle(Real _Radian1, Real _Radian2);
	/*! 
	*
	*/
	Real Angle(Vec2 Argument1, Vec2 Argument2);
	/*! 
	*
	*/
	Real OrientedAngle(Vec2 Argument1, Vec2 Argument2);
	/*! 
	*
	*/
	Real PI();
	/*! 
	*
	*/
	Real Asin(Real Argument1);
	/*! 
	*
	*/
	Real Acos(Real Argument1);
	/*! 
	*
	*/
	Real Pow(Real Argument1, Real Argument2);
	/*! 
	*
	*/
	Real Ln(Real Argument1);
	/*! 
	*
	*/
	Real Sqrt(Real Argument1);
	/*! 
	* \brief Returns the maximum between A and B
	* 
	*
	*/
	Integer Max(Integer _A, Integer _B);
	/*! 
	* \brief Returns the minimum between A and B
	* 
	*
	*/
	Integer Min(Integer _A, Integer _B);
	/*! 
	* \brief Returns the value X clamped to the range Min..Max
	* 
	*
	*/
	Integer Clamp(Integer _X, Integer _Min, Integer _Max);
	/*! 
	* \brief Returns the maximum between A and B
	* 
	*
	*/
	Real Max(Real _A, Real _B);
	/*! 
	* \brief Returns the minimum between A and B
	* 
	*
	*/
	Real Min(Real _A, Real _B);
	/*! 
	* \brief Returns the value X clamped to the range Min..Max
	* 
	*
	*/
	Real Clamp(Real _X, Real _Min, Real _Max);
	/*! 
	* \brief Returns the modulus of X in the range Min..Max
	* 
	*
	*/
	Real Mod(Real _X, Real _Min, Real _Max);
};

/*!
* \brief Standard Text manipulation functions.
*/
namespace TextLib {

	/*! 
	* \brief Returns the Real corresponding to _Text
	* 
	* Returns -1 if an invalid Text is given
	* 
	* \param _Text : The text you want to convert into a Real
	*
	*/
	Real ToReal(Text _Text);
	/*! 
	* \brief Returns the Integer corresponding to _Text
	* 
	* Returns -1 if an invalid Text is given
	* 
	* \param _Text : The text you want to convert into an Integer
	*
	*/
	Integer ToInteger(Text _Text);
	/*! 
	* \brief Returns the RGB color corresponding to _Text
	* 
	* Returns an empty Vec3 if an invalid Text is given
	* 
	* \param _Text : The text you want to convert into a RGB color
	*
	*/
	Vec3 ToColor(Text _Text);
	/*! 
	* \brief Returns a substring of _Text
	* 
	* Returns the substring of _Text beginning at the _Start index, with a length of _Length chars 
	* Returns an empty Text if _Start > Text.Length or _Length == 0
	* 
	* \param _Text : The text in which we look for the substring
	* \param _Start : The beginning index of the substring
	* \param _Length : The length of the substring
	*
	*/
	Text SubString(Text _Text, Integer _Start, Integer _Length);
	/*! 
	* \brief Returns a substring of _Text
	* 
	* Returns the substring of _Text beginning at the _Start index, with a length of _Length chars 
	* Returns an empty Text if _Start > Text.Length or _Length == 0
	* 
	* \param _Text : The text in which we look for the substring
	* \param _Start : The beginning index of the substring
	* \param _Length : The length of the substring
	*
	*/
	Text SubText(Text _Text, Integer _Start, Integer _Length);
	/*! 
	* \brief Returns the length of _Text
	* 
	* \param _Text : The text you want the length
	*
	*/
	Integer Length(Text _Text);
	/*! 
	* \brief Returns the Text corresponding to _Integer
	* 
	* \param _Integer : The Integer you want to convert
	*
	*/
	Text ToText(Integer _Integer);
	/*! 
	* \brief Returns the Text corresponding to _Real
	* 
	* \param _Real : The Real you want to convert
	*
	*/
	Text ToText(Real _Real);
	/*! 
	* \brief Returns the Text corresponding to _Boolean
	* 
	* \param _Boolean : The Boolean you want to convert
	*
	*/
	Text ToText(Boolean _Boolean);
	/*! 
	* \brief Returns the Text corresponding to _Int3
	* 
	* \param _Int3 : The Int3 you want to convert
	*
	*/
	Text ToText(Int3 _Int3);
	/*! 
	* \brief Returns the Text corresponding to _Vec3
	* 
	* \param _Vec3 : The Vec3 you want to convert
	*
	*/
	Text ToText(Vec3 _Vec3);
	/*! 
	* \brief Returns the Text corresponding to _Time
	* 
	* Converts a _Time Integer to a Text with the format HhMmSs
	*
	* Hh will be hidden if _Time is less than one hour.
	* 
	* \param _Time : The time you want to convert into a Text
	*
	*/
	Text TimeToText(Integer _Time);
	/*! 
	* \brief Returns the Text corresponding to _Time
	* 
	* Converts a _Time Integer to a Text with the following format :
	* - HhMmSsCc if IncludeCentiSeconds is True
	* - HhMmSs if there's no activated option
	*
	* Hh will be hidden if _Time is less than one hour.
	* 
	* \param _Time : The time you want to convert into a Text
	* \param _IncludeCentiSeconds : Set IncludeCentiSeconds to True if you want the CentiSeconds to be displayed in the returned Text
	*
	*/
	Text TimeToText(Integer _Time, Boolean _IncludeCentiSeconds);
	/*! 
	* \brief Returns the Text corresponding to _Time
	* 
	* Converts a _Time Integer to a Text with the following format :
	* - HhMmSsMil if IncludeMilliSeconds is True
	* - HhMmSsCc if IncludeCentiSeconds is True
	* - HhMmSs if there's no activated option
	*
	* Hh will be hidden if _Time is less than one hour.
	* 
	* \param _Time : The time you want to convert into a Text
	* \param _IncludeCentiSeconds : Set IncludeCentiSeconds to True if you want the CentiSeconds to be displayed in the returned Text
	* \param _IncludeMilliSeconds : Set IncludeMilliSeconds to True if you want the MilliSeconds to be displayed in the returned Text
	*
	*/
	Text TimeToText(Integer _Time, Boolean _IncludeCentiSeconds, Boolean _IncludeMilliSeconds);
	/*! 
	* \brief Returns the Text corresponding to _Color
	* 
	* \param _Color : The color you want to convert into a text
	*
	*/
	Text ColorToText(Vec3 _Color);
	/*! 
	*
	*/
	Text FormatInteger(Integer Argument1, Integer Argument2);
	/*! 
	* \brief Returns the rank corresponding to a number, formatted according to the locale.  ShortFormat: '25k' otherwise '25654th'.
	* 
	*
	*/
	Text FormatRank(Integer _Rank, Boolean _ShortFormat);
	/*! 
	* \brief Returns the Text corresponding to a Real. With formatting
	* 
	* \param _Value : The Real value you want to convert
	* \param _FPartLength : The number of digits you want for the FPart
	* \param _HideZeroes : Hide trailing zeroes
	* \param _HideDot : Hide trailing dot if there is nothing after it
	*
	*/
	Text FormatReal(Real _Value, Integer _FPartLength, Boolean _HideZeroes, Boolean _HideDot);
	/*! 
	* \brief Changes lower case characters to upper case characters
	* 
	*
	*/
	Text ToUpperCase(Text _TextToChange);
	/*! 
	* \brief Changes upper case characters to lower case characters
	* 
	*
	*/
	Text ToLowerCase(Text _TextToChange);
	/*! 
	* \brief Return a string where the previously unclosed $< tags have their $> counterpart
	* 
	*
	*/
	Text CloseStyleTags(Text _String);
	/*! 
	* \brief Compares texts without taking format characters in account.
	* 
	* Returns True if Text1 and Text2 are equal. 
	* Format differences are not taken into account. 
	* Case differences are taken into account if IsCaseSensitive is set to True.
	* 
	*
	*/
	Boolean CompareWithoutFormat(Text _Text1, Text _Text2, Boolean _IsCaseSensitive);
	/*! 
	* \brief Returns True if the searched text is found in the text to search in.
	* 
	* Format is not taken into account if IsFormatSensitive is set to False. 
	* Case is not taken into account if IsCaseSensitive is set to False.
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	* \param _IsFormatSensitive : True if you want to take Format into account, False elseway
	* \param _IsCaseSensitive : True if you want to take Case into account, False elseway
	*
	*/
	Boolean Find(Text _TextToFind, Text _TextToSearchIn, Boolean _IsFormatSensitive, Boolean _IsCaseSensitive);
	/*! 
	* \brief Return True if the Text ends with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	*
	*/
	Boolean EndsWith(Text _TextToFind, Text _TextToSearchIn);
	/*! 
	* \brief Return True if the Text ends with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	* \param _IsFormatSensitive : True if you want to take Format into account, False elseway
	* \param _IsCaseSensitive : True if you want to take Case into account, False elseway
	*
	*/
	Boolean EndsWith(Text _TextToFind, Text _TextToSearchIn, Boolean _IsFormatSensitive, Boolean _IsCaseSensitive);
	/*! 
	* \brief Return True if the Text starts with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	*
	*/
	Boolean StartsWith(Text _TextToFind, Text _TextToSearchIn);
	/*! 
	* \brief Return True if the Text starts with the TextToFind
	* 
	* \param _TextToFind : The text you are looking for
	* \param _TextToSearchIn : The text you are searching in
	* \param _IsFormatSensitive : True if you want to take Format into account, False elseway
	* \param _IsCaseSensitive : True if you want to take Case into account, False elseway
	*
	*/
	Boolean StartsWith(Text _TextToFind, Text _TextToSearchIn, Boolean _IsFormatSensitive, Boolean _IsCaseSensitive);
	/*! 
	*
	*/
	Text Compose(Text Argument1);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4, Text Argument5);
	/*! 
	*
	*/
	Text Compose(Text Argument1, Text Argument2, Text Argument3, Text Argument4, Text Argument5, Text Argument6);
	/*! 
	*
	*/
	Text MLEncode(Text Argument1);
	/*! 
	*
	*/
	Text URLEncode(Text Argument1);
	/*! 
	*
	*/
	Text StripFormatting(Text Argument1);
	/*! 
	* \brief Splits a given text based on a given separators set.
	* 
	* \param _Separators : The separators to use
	* \param _Text : The text to split.
	*
	*/
	Array<Text> Split(Text _Separators, Text _Text);
	/*! 
	* \brief Joins a set of texts with the given separator
	* 
	* \param _Separator : The separator to use
	* \param _Texts : The texts to join.
	*
	*/
	Text Join(Text _Separator, Array<Text> _Texts);
	/*! 
	*
	*/
	Text Trim(Text Argument1);
	/*! 
	*
	*/
	Text ReplaceChars(Text Argument1, Text Argument2, Text Argument3);
	/*! 
	* \brief Replaces occurences of _ToReplace in _Text with _Replacement
	* 
	* \param _Text : The text you search in
	* \param _ToReplace : The text you want to replace
	* \param _Replacement : The text you want to insert
	*
	*/
	Text Replace(Text _Text, Text _ToReplace, Text _Replacement);
	/*! 
	* \brief Find occurences of the _Pattern in the _Text.
	* 
	* \param _Pattern : Pattern is a regular expression, similar to javascript syntax.
	* \param _Text : 
	* \param _Flags : Flags can be 'g' to find all occurences, 'i' to ignore case, 'm' for multiline mode.
	*
	*/
	Array<Text> RegexFind(Text _Pattern, Text _Text, Text _Flags);
	/*! 
	* \brief Captures the groups of the _Pattern in the matching _Text. group[0] is the whole pattern match.
	* 
	* \param _Pattern : Pattern is a regular expression, similar to javascript syntax.
	* \param _Text : 
	* \param _Flags : Flags can be 'i' to ignore case, 'm' for multiline mode.
	*
	*/
	Array<Text> RegexMatch(Text _Pattern, Text _Text, Text _Flags);
	/*! 
	* \brief Replace the _Pattern in the matching text with _Replacement.
	* 
	* \param _Pattern : Pattern is a regular expression, similar to javascript syntax.
	* \param _Text : 
	* \param _Flags : Flags can be 'g' to find all occurences, 'i' to ignore case, 'm' for multiline mode.
	* \param _Replacement : 
	*
	*/
	Text RegexReplace(Text _Pattern, Text _Text, Text _Flags, Text _Replacement);
	/*! 
	* \brief Lookup the text in the current translation dictionary.
	* 
	* Lookup the text in the current translation dictionary, and returns the translation, or returns the original text if not found.
	* 
	*
	*/
	Text GetTranslatedText(Text _Text);
};

/*!
* \brief Standard map coordinates manipulation functions.
*/
namespace MapUnits {

	/*! 
	*
	*/
	CMapEditorPlugin::CardinalDirections GetNextDir(CMapEditorPlugin::CardinalDirections Argument1);
	/*! 
	*
	*/
	CMapEditorPlugin::CardinalDirections GetPreviousDir(CMapEditorPlugin::CardinalDirections Argument1);
	/*! 
	*
	*/
	CMapEditorPlugin::CardinalDirections GetOpposedDir(CMapEditorPlugin::CardinalDirections Argument1);
	/*! 
	*
	*/
	CMapEditorPlugin::CardinalDirections AddDirs(CMapEditorPlugin::CardinalDirections Argument1, CMapEditorPlugin::CardinalDirections Argument2);
	/*! 
	*
	*/
	CMapEditorPlugin::CardinalDirections SubDirs(CMapEditorPlugin::CardinalDirections Argument1, CMapEditorPlugin::CardinalDirections Argument2);
	/*! 
	*
	*/
	Int3 GetNeighbourCoord(Int3 Argument1, CMapEditorPlugin::CardinalDirections Argument2);
	/*! 
	*
	*/
	Int3 GetRotatedOffset(Int3 Argument1, CMapEditorPlugin::CardinalDirections Argument2);
	/*! 
	*
	*/
	Int3 GetRotatedOffsetPositive(Int3 Argument1, CMapEditorPlugin::CardinalDirections Argument2, Int3 Argument3);
};

/*!
* \brief Standard animation functions.
*/
namespace AnimLib {

	/*! 
	* \brief Returns the value smoothly transitionning from 0 to 1
	* 
	*
	*/
	Real SmoothStep(Real _X);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using Robert Penner easing functions. Function must be one of:  "Linear", "QuadIn", "QuadOut", "QuadInOut", "CubicIn", "CubicOut", "CubicInOut", "QuartIn", "QuartOut", "QuartInOut", "QuintIn", "QuintOut", "QuintInOut", "SineIn", "SineOut", "SineInOut", "ExpIn", "ExpOut", "ExpInOut", "CircIn", "CircOut", "CircInOut", "BackIn", "BackOut", "BackInOut", "ElasticIn", "ElasticOut", "ElasticInOut", "ElasticIn2", "ElasticOut2", "ElasticInOut2", "BounceIn", "BounceOut", "BounceInOut"
	* 
	*
	*/
	Real Ease(Text _Function, Real _T, Real _Base, Real _Change, Real _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseLinear(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutQuad(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutCubic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutQuart(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutQuint(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutSine(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutExp(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutCirc(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutBack(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutElastic(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutElastic2(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseOutBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
	/*! 
	* \brief Returns the value animated from Base to Base+Delta using R. Penner easing functions.
	* 
	*
	*/
	Real EaseInOutBounce(Integer _T, Real _Base, Real _Change, Integer _Duration);
};

/*!
* \brief Standard time manipulation functions.
*/
namespace TimeLib {

	/*!
	
	*/
	enum EDateFormats {
		Full,
		Date,
		DateShort,
		Time,
		TimeShort,
		Relative,
		RelativeShort,
	};
	/*!
	
	*/
	enum EDurationFormats {
		Full,
		Abbreviated,
		Chrono,
	};
	/*! 
	* \brief Returns the date corresponding to a timestamp, formatted according to the locale. Not available on servers.
	* 
	* \param _Timestamp : Timestamp to format
	* \param _Format : Format
	*
	*/
	Text FormatDate(Text _Timestamp, EDateFormats _Format);
	/*! 
	* \brief Returns the duration between 2 timestamps, formatted according to the locale. Not available on servers.
	* 
	* \param _Timestamp1 : Timestamp1
	* \param _Timestamp2 : Timestamp2
	* \param _Format : Format
	*
	*/
	Text FormatDelta(Text _Timestamp1, Text _Timestamp2, EDurationFormats _Format);
	/*! 
	* \brief Returns the duration Delta formatted according to the locale. Not available on servers.
	* 
	* \param _Delta : Delta in seconds
	* \param _Format : Format
	*
	*/
	Text FormatDelta(Text _Delta, EDurationFormats _Format);
	/*! 
	* \brief Compares 2 timestamps
	* 
	* \param _Timestamp1 : Unix timestamp
	* \param _Timestamp2 : Unix timestamp
	*
	*/
	Integer Compare(Text _Timestamp1, Text _Timestamp2);
	/*! 
	* \brief Returns a Real between 0 and 1, given an interval and a timestamp
	* 
	* \param _Boundary1 : Lower boundary defining the time interval
	* \param _Boundary2 : Higher boundary defining the time interval
	* \param _Timestamp : Timestamp to check
	*
	*/
	Real Clamp01(Text _Boundary1, Text _Boundary2, Text _Timestamp);
	/*! 
	* \brief Returns a Real between 0 and 1, given a timestamp, according to the day cycle in local timezone
	* 
	* \param _Timestamp : Timestamp to check
	*
	*/
	Real Clamp01TZDay(Text _Timestamp);
	/*! 
	* \brief Returns a Real between 0 and 1, given a timestamp, according to the day cycle in UTC timezone
	* 
	* \param _Timestamp : Timestamp to check
	*
	*/
	Real Clamp01UTCDay(Text _Timestamp);
	/*! 
	* \brief Gets current timestamp
	* 
	*
	*/
	Text GetCurrent();
	/*! 
	* \brief Returns the duration in seconds between 2 timestamps. May be clamped if huge.
	* 
	* \param _Timestamp1 : First timestamp. Result will be positive if this one is bigger/more recent
	* \param _Timestamp2 : Second timestamp
	*
	*/
	Integer GetDelta(Text _Timestamp1, Text _Timestamp2);
};

/*!
* \brief Standard color manipulation functions.
*/
namespace ColorLib {

	/*! 
	*
	*/
	Vec3 HsvToRgb(Vec3 __Hsv);
	/*! 
	*
	*/
	Vec3 RgbToHsv(Vec3 __Rgb);
	/*! 
	* \brief Returns the Hexa3 corresponding to the RGB given.
	* 
	*
	*/
	Text RgbToHex3(Vec3 __Rgb);
	/*! 
	* \brief Returns the Hexa6 corresponding to the RGB given.
	* 
	*
	*/
	Text RgbToHex6(Vec3 __Rrggbb);
	/*! 
	* \brief Returns the RGB color corresponding to Hex3.
	* 
	* Returns an empty Vec3 if an invalid Text is given.
	* 
	* \param _Text : The text you want to convert into a RGB color.
	*
	*/
	Vec3 Hex3ToRgb(Text _Text);
	/*! 
	* \brief Returns the RGB color corresponding to Hex6.
	* 
	* Returns an empty Vec3 if an invalid Text is given.
	* 
	* \param _Text : The text you want to convert into a RGB color.
	*
	*/
	Vec3 Hex6ToRgb(Text _Text);
	/*! 
	* \brief Returns the RGB color corresponding to Hex.
	* 
	* Returns an empty Vec3 if an invalid Text is given.
	* 
	* \param _Text : The text you want to convert into a RGB color.
	*
	*/
	Vec3 HexToRgb(Text _Text);
};

